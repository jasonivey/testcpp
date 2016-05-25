flags = [
        '-Wall',
        '-Wextra',
        '-I/home/jasonivey/dev/testcpp',
        '-g',
        '-O0',
        '-std=c++14',
        '-stdlib=libc++',
        '-fPIC',
        '-DDEBUG',
        ]

def FlagsForFile(filename, **kwargs):
  return {'flags': flags, 'do_cache': True}
