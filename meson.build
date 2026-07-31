project('terminal_renderer_lib',
        ['cpp', 'c'],
        default_options : [
            'warning_level=3',
            'cpp_std=c++20'
        ],
)

incdirs = [
    include_directories('include'),
]

run_command('bash', './generate_meson_files.sh', 'src', 'src', check: true)

src = []
subdir('src')

lib = shared_library(
    'terminal_renderer_lib',
    sources: src,
    include_directories: incdirs,
    install : true,
)

renderer_dep = declare_dependency(
    link_with: lib,
    include_directories: incdirs,
)

meson.override_dependency('terminal_renderer_lib', renderer_dep)

example = executable(
    'TerminalRendererExample',
    sources: ['example/main.cpp'],
    dependencies: [renderer_dep],
)

install_subdir(
    'include/terminal_renderer',
    install_dir: get_option('includedir')
)

pkg = import('pkgconfig')

pkg.generate(
    lib,
    name: 'terminal_renderer_lib',
    description: 'A simple cpp terminal rendering library',
    version: meson.project_version()
)
