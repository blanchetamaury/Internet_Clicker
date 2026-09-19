project(
  'Internet_Clicker',
  'c',
  meson_version : '>= 1.3.0',
)

cc = meson.get_compiler('c')

dependencies = [
  dependency('sdl2'),
  dependency('SDL2_image', static: true),
  dependency('SDL2_mixer', static: true),
  dependency('SDL2_ttf', static: true),
  cc.find_library('m', required : true),
]

conf_data = configuration_data()
install_path = join_paths(get_option('prefix'), get_option('datadir'), 'InternetClicker/')
conf_data.set('INSTALL_DATA', install_path)

sources = files(
  'GAME/main.c',
  'GAME/TEXTURE/ft_find_texture.c',
  'GAME/TEXTURE/init_rect_for_texture.c',
  'GAME/TEXTURE/load_texture.c',
  'GAME/LOADING/loading_loop.c',
  'GAME/LOADING/ft_process_screens.c',
  'GAME/LEVEL1/level1_loop.c',
  'GAME/OTHER/ft_free.c',
  'GAME/OTHER/init_text.c',
  'GAME/OTHER/list_create.c',
  'GAME/MENU/event_loop.c',
  'GAME/MENU/menu_loop.c',
  'GAME/MENU/menu_btn.c',
  'GAME/MENU/menu_settings.c',
  'GAME/MENU/menu_all.c',
  'GAME/MENU/menu_theme_bg.c',
)

# Build the executable

inc_directories = include_directories('GAME/INCLUDE')

executable(
  'Internet_Clicker',
  sources,
  configure_file(input : 'GAME/INCLUDE/config.h.in', output : 'config.h', configuration : conf_data),
  dependencies : dependencies,
  include_directories : inc_directories,
  install : true,
)


# Install data files

install_data('data/Internet-Clicker.desktop', install_dir : join_paths(get_option('datadir'), 'applications'))
install_data('UTILITAIRE/icon.png', install_dir : join_paths(get_option('datadir'), 'icons/hicolor/256x256/apps/'), 
  rename : 'Internet-Clicker.png'
)
install_subdir('data/FONT', install_dir : join_paths(get_option('datadir'), 'InternetClicker'))
install_subdir('data/IMAGE', install_dir : join_paths(get_option('datadir'), 'InternetClicker'))
install_subdir('data/MUSIQUE', install_dir : join_paths(get_option('datadir'), 'InternetClicker'))
