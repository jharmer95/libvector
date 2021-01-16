# Static Library
libvec_sources = ['vector.c']
libvec_includes = [include_dir]

libvec_warnings = project_warnings

if get_option('default_library') == 'shared'
    libvec = library('vector', libvec_sources, c_args : libvec_warnings, include_directories : libvec_includes, install : false)
else
    libvec_warnings += ['-fpic', '-shared']
    libvec = library('vector', libvec_sources, c_args : libvec_warnings, include_directories : libvec_includes, install : true)
endif

# Executable
vec_exe_warnings = project_warnings + ['-DVECTOR_OPT_IN', '-DVECTOR_ENABLE_INT']
vec_exe_sources = ['test.c']
vec_exe_includes = [include_dir]
vec_exe_links = [libvec]

if get_option('hardened')
    vec_exe_warnings += ['-Wl,-pie']
    vec_exe = executable('libvec_test', vec_exe_sources, c_args : vec_exe_warnings, include_directories : vec_exe_includes, link_with : vec_exe_links, install : false, pie : true)
else
    vec_exe = executable('libvec_test', vec_exe_sources, c_args : vec_exe_warnings, include_directories : vec_exe_includes, link_with : vec_exe_links, install : false)
endif
