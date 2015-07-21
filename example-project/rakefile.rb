require 'ceedling'
Ceedling.load_project

# The location of the compiled TivaWare Peripheral Driver Library.
driverlib = "lib/TivaWare/driverlib/gcc/libdriver.a"

# Run all tests and build the release by default.
task :default => %w[ test:all release ]

# The release build requires driverlib to be built first.
task :release => "#{driverlib}"

file "#{PROJECT_BUILD_ROOT}/release/project.bin" => :release do |task|
    puts "Creating #{File.basename(task.name)}..."
    sh "arm-none-eabi-objcopy -O binary #{PROJECT_BUILD_ROOT}/release/#{RELEASE_BUILD_OUTPUT} #{task.name}"
end

desc "Load the binary onto the Tiva C Launchpad board"
task :load => "#{PROJECT_BUILD_ROOT}/release/project.bin" do
    puts "Loading to board..."
    sh "lm4flash #{PROJECT_BUILD_ROOT}/release/project.bin"
end

# Build instructions for the TivaWare Peripheral Driver Library (i.e. "driverlib").
namespace :driverlib do

    driverlib_src_path = "lib/TivaWare/driverlib"

    desc "Build TivaWare Peripheral Driver Library"
    task :build => "#{driverlib}"

    file "#{driverlib}" do |task| 
        puts "Building #{File.basename(task.name)}..."
        chdir("#{driverlib_src_path}") do
            sh "make"
        end
    end

    desc "Clean TivaWare Peripheral Driver Library"
    task :clean do |task|
        puts "Cleaning #{File.basename(task.name)}..."
        chdir("#{driverlib_src_path}") do
            sh "make clean"
        end
    end

end