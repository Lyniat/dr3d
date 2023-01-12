#include <dragonruby.h>
#include "renderer.h"
#include "api.h"

DRB_FFI

extern "C" {
    DRB_FFI_EXPORT
    void drb_register_c_extensions_with_api(mrb_state *state, struct drb_api_t *api) {
        drb_api = api;
        struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
        struct RClass *module = drb_api->mrb_define_module_under(state, FFI, "CExt");

        drb_api->mrb_define_module_function(state, module, "setup_renderer",{[](mrb_state *_mrb, mrb_value self){
            setup_renderer();
            return mrb_nil_value();
        }}, MRB_ARGS_REQ(0));

        drb_api->mrb_define_module_function(state, module, "render_frame",{[](mrb_state *_mrb, mrb_value self){
            mrb_int up, down, left, right;
            drb_api->mrb_get_args(_mrb,"iiii", &up, &down, &left, &right);
            render_frame(up, down, left, right);
            return mrb_nil_value();
        }}, MRB_ARGS_REQ(4));
    }
}
