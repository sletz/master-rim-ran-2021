#include "plugin.hpp"

struct MyModule : Module {
	enum ParamIds {
		PARAM1_PARAM,
		PARAM2_PARAM,
		PARAM3_PARAM,
		PARAM4_PARAM,
		NUM_PARAMS
	};
	enum InputIds {
		INPUT1_INPUT,
		INPUT2_INPUT,
		NUM_INPUTS
	};
	enum OutputIds {
		OUTPUT1_OUTPUT,
		OUTPUT2_OUTPUT,
		NUM_OUTPUTS
	};
	enum LightIds {
		NUM_LIGHTS
	};
    
 
    // Contruction du plugin
    MyModule(){
		config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
		configParam(PARAM1_PARAM, 0.f, 1.f, 0.f, "");
		configParam(PARAM2_PARAM, 0.f, 1.f, 0.f, "");
		configParam(PARAM3_PARAM, 0.f, 1.f, 0.f, "");
		configParam(PARAM4_PARAM, 0.f, 1.f, 0.f, "");
        
   	}
    
    // Destruction du plugin
    ~MyModule(){}

    // Traitement des échantillons
	void process(const ProcessArgs& args) override {
        
	}
};


struct MyModuleWidget : ModuleWidget {
	MyModuleWidget(MyModule* module) {
		setModule(module);
		setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/MyModule.svg")));

		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(8.002, 21.161)), module, MyModule::PARAM1_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(22.705, 21.161)), module, MyModule::PARAM2_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(7.877, 42.705)), module, MyModule::PARAM3_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(22.92, 42.857)), module, MyModule::PARAM4_PARAM));

		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(8.569, 75.336)), module, MyModule::INPUT1_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(22.894, 75.336)), module, MyModule::INPUT2_INPUT));

		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(8.323, 100.332)), module, MyModule::OUTPUT1_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(22.92, 100.332)), module, MyModule::OUTPUT2_OUTPUT));
	}
};


Model* modelMyModule = createModel<MyModule, MyModuleWidget>("MyModule");
