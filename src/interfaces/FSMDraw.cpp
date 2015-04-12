#include "FSMDraw.h"

using namespace std;

FSMDraw::FSMDraw(){}

void FSMDraw::Draw_FSM(string name, FSM* fsm){
	Generate_dot(name, fsm);
	Generate_svg(name);
}

void FSMDraw::Generate_dot(string name, FSM* fsm){
	string dot_text = "digraph links {\n";
	vector <state*> states = fsm->Get_states();
	for(size_t i = 0; i < states.size(); i++){
		dot_text += "\t" + states[i]->name + ";\n";
	}
	for(size_t i = 0; i < states.size(); i++){
		for(size_t j = 0; j < states[i]->transitions.size(); j++){
			transition* trans = states[i]->transitions[j];
			dot_text += "\t" + states[i]->name + "->" + trans->state_to;
			dot_text += " [label = \"" + trans->trigger + "/" + trans->condition + "/" + trans->action + "\"] [minlen=5]\n";
		}
	}
	dot_text += "}";
	ofstream out_file;
	out_file.open("./test/" + name + ".gv");
	out_file << dot_text;
	out_file.close();
}

void FSMDraw::Generate_svg(string name){
	#ifdef ENABLE_GRAPHVIZ	
		FILE *dot_file = fopen(("./test/" + name + ".gv").c_str(), "r");
		FILE *svg_file = fopen(("./test/" + name + ".svg").c_str(), "w");
		GVC_t *gvc = gvContext();
		Agraph_t *g = agread(dot_file);
		gvLayout(gvc, g, "dot");
		gvRender(gvc, g, "svg", svg_file);
		gvFreeLayout(gvc, g);
		agclose(g);
		gvFreeContext(gvc);
		fclose(dot_file);
		fclose(svg_file);
	#else
		cout << "[Warning] You are trying to draw FSM graph with Graphviz disabled." << endl;
	#endif
}
