TARGET = 'test-pubsub'

env = Environment()

files = []
files.append( Glob('*.cpp') )

clean_list = []
clean_list.append('sconsign.dblite')
clean_list.append('core*')
env.Clean('default', clean_list)

env.Append( CPPPATH = ['.'] )

env.Append( CPPFLAGS = ['-g'] )
env.Append( CPPFLAGS = ['-std=c++11'] )
env.Append( CPPFLAGS = ['-Wfatal-errors'] )

env.Append( LIBS = ['pthread'] )


env.Program(TARGET, source = files)


