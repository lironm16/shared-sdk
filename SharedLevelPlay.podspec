Pod::Spec.new do |s|
  s.name             = 'SharedLevelPlay'
  s.version          = '1.local'
  s.summary          = 'Shared for LevelPlay'
  s.description      = 'Local shared for development.'
  s.homepage         = "http://www.is.com/"
  s.license          = { :type => 'Commercial', :text => 'https://platform.ironsrc.com/partners/terms-and-conditions-new-user' }
  s.author           = { "IronSource" => "http://www.is.com/contact/" }
  s.source           = { :path => 'build' }
  s.static_framework = true
  s.platform         = :ios, '12.0'
  s.swift_version    = '5.0'

  # Update prepare_command to check for and build the framework in the build folder
  s.prepare_command = <<-CMD
    if [ ! -d "build/shared.xcframework" ]; then
      echo "shared.xcframework missing. Running build script..."
      ./scripts/build_shared_xcframework.sh
    fi
  CMD

  # Point vendored_frameworks to the new build location
  s.vendored_frameworks = 'build/shared.xcframework'
  s.preserve_paths = 'build/shared.xcframework'
end
