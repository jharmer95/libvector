project('libvec', 'c', version : '0.1.0', license : ['MIT'], default_options : ['c_std=gnu17', 'warning_level=3', 'werror=true', 'default_library=shared'])

cc = meson.get_compiler('c')
build_type = get_option('buildtype')

if cc.get_id() == 'gcc'
    project_warnings = ['-Wall', '-Wextra', '-Wpedantic', '-Wshadow', '-Wcast-align', '-Wunused', '-Wconversion', '-Wsign-conversion', '-Wdouble-promotion', '-Wformat=2', '-Wlogical-op', '-Wduplicated-branches', '-Wduplicated-cond', '-Wmisleading-indentation', '-Wswitch-enum', '-Werror=format-security', '-Werror=implicit-function-declaration', '-Wno-padded']
elif cc.get_id() == 'clang'
    project_warnings = ['-Weverything', '-Wno-padded']
endif

if build_type.startswith('debug')
    project_warnings += ['-grecord-gcc-switches']
endif

if get_option('hardened')
    project_warnings += ['-fno-lto', '-grecord-gcc-switches', '-D_FORTIFY_SOURCE=2', '-D_GLIBCXX_ASSERTIONS', '-fstack-clash-protection', '-fstack-protector-strong', '-mshstk', '-fcf-protection', '-Wl,-z,defs', '-Wl,-z,now', '-Wl,-z,relro', '-fplugin=annobin']
endif

subdir('include')
subdir('src')
