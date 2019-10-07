# Teapot v2.0.0 configuration generated at 2017-09-11 10:45:16 +1200

required_version "3.0"

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
	target.depends 'Language/C++14'
	
	target.provides 'Library/Streams' do
		source_root = target.package.path + 'source'
	
		library_path = build static_library: 'Streams', source_files: source_root.glob('Streams/**/*.cpp')
		
		append linkflags library_path
		append header_search_paths source_root
	end
end

define_target 'streams-test' do |target|
	target.depends 'Library/UnitTest'
	target.depends 'Library/Streams'
	
	target.depends 'Language/C++14'
	
	target.provides 'Test/Streams' do |*arguments|
		test_root = target.package.path + 'test'
		
		run source_files: test_root.glob('Streams/**/*.cpp'), arguments: arguments
	end
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
