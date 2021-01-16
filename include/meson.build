conf_data = configuration_data()
conf_data.set('version', meson.project_version())
configure_file(input : 'version.h.in', output : 'version.h', configuration : conf_data)
include_dir = include_directories('.')

header_list = ['vector.h', 'OOP.h']

install_headers(header_list)
