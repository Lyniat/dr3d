$gtk.ffi_misc.gtk_dlopen("ext")
include FFI::CExt

def tick args
  if args.state.tick_count == 0
    setup_renderer
  end
  args.state.rotation ||= 0

  up = args.inputs.keyboard.key_held.w ? 1 : 0
  down = args.inputs.keyboard.key_held.s ? 1 : 0
  left = args.inputs.keyboard.key_held.a ? 1 : 0
  right = args.inputs.keyboard.key_held.d ? 1 : 0
  render_frame(up, down, left, right)

  w = 1280
  h = 720
  args.outputs.background_color = [0, 0, 0]
  args.outputs.sprites << [0, 0, w, h, :dr3d]

  args.outputs.primitives << args.gtk.current_framerate_primitives
end

