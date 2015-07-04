require 'ceedling'

Ceedling.load_project

task :default => %w[ test:all release ]

file "#{PROJECT_BUILD_ROOT}/release/project.bin" => :release do |task|
    puts "Creating #{File.basename(task.name)}..."
    sh "arm-none-eabi-objcopy -O binary #{PROJECT_BUILD_ROOT}/release/#{RELEASE_BUILD_OUTPUT} #{task.name}"
end

task :load => "#{PROJECT_BUILD_ROOT}/release/project.bin" do
    puts "Loading to board..."
    sh "lm4flash #{PROJECT_BUILD_ROOT}/release/project.bin"
end