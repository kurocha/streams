# Teapot v2.0.0 configuration generated at 2017-09-11 10:45:16 +1200

required_version "2.0"

# Project Metadata

define_project "streams" do |project|
	project.title = "Streams"
	project.summary = 'A brief one line summary of the project.'
	
	project.license = 'MIT License'
	
	project.add_author 'Samuel Williams', email: 'samuel.williams@oriontransfer.co.nz'
	
	project.version = '0.1.0'
end

# Build Targets

define_target 'streams-library' do |target|
	target.build do
		source_root = target.package.path + 'source'
		copy headers: source_root.glob('Streams/**/*.{h,hpp}')
		build static_library: 'Streams', source_files: source_root.glob('Streams/**/*.cpp')
	end
	
	target.depends 'Build/Files'
	target.depends 'Build/Clang'
	
	target.depends :platform
	target.depends 'Language/C++14', private: true
	
	target.provides 'Library/Streams' do
		append linkflags [
			->{install_prefix + 'lib/libStreams.a'},
		]
	end
end

define_target 'streams-test' do |target|
	target.build do |*arguments|
		test_root = target.package.path + 'test'
		
		run tests: 'Streams', source_files: test_root.glob('Streams/**/*.cpp'), arguments: arguments
	end
	
	target.depends 'Library/UnitTest'
	target.depends 'Library/Streams'
	target.depends 'Language/C++14', private: true
	
	target.provides 'Test/Streams'
end

# Configurations

define_configuration 'development' do |configuration|
	configuration[:source] = "http://github.com/kurocha"
	configuration.import "streams"
	
	# Provides all the build related infrastructure:
	configuration.require 'platforms'
	
	# Provides unit testing infrastructure and generators:
	configuration.require 'unit-test', import: false
	
	# Provides some useful C++ generators:
	configuration.require 'generate-cpp-class'
	
	configuration.require "generate-project"
	configuration.require "generate-travis"
end

define_configuration "streams" do |configuration|
	configuration.public!
end
