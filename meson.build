project(
  'CLox',
  'c',
  version : '0.1',
  default_options: [
    'warning_level=3',
    'werror=true',
    'buildtype=debug',
    'debug=true',
    #'optimization=3',
    'c_std=c18'
  ]
)

SRC = [
  'src/main.c',
  'src/error.c',
  'src/run.c',
  'src/string.c',
]

INC = include_directories('include')

DEPS = [

]

executable(
          'clox',
          SRC, 
          install : true,
          include_directories: INC,
          dependencies: DEPS,
)
