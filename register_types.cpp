#include "register_types.h"
#include "gdtest.h"
#include "core/os/os.h"

using namespace godot;

void initialize_gdtest_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	GDREGISTER_CLASS(GDTest);
	//выполняется только во время выполнения игры
	//GDREGISTER_RUNTIME_CLASS
	OS::get_singleton()->print("GDTestModule: class GDTest register!\n");
}

void uninitialize_gdtest_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}
