cd %~dp0
cd ..
cd src
rem dotnet tool install Microsoft.CodeCoverage.Console --global
set VSCOVERAGEPATH="C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Team Tools\Dynamic Code Coverage Tools\CodeCoverage.exe"
set vsTestConsole="C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\CommonExtensions\Microsoft\TestWindow\vstest.console.exe" 
set sonarscanner="C:\Software\sonar-scanner-msbuild-5.7.2\sonar-scanner-4.7.0.2747\bin\sonar-scanner.bat"
rem delete all existing *.coverage and *.coveragexml files
del /s *.coverage
del /s *.coveragexml
del /s *.xml
rem https://github.com/SonarOpenCommunity/sonar-cxx/wiki/sonar.cxx.vscoveragexml.reportPaths
call %VSCOVERAGEPATH%  collect /output:"report.coverage" %vsTestConsole%  "x64\Debug\UnitTestCppDemo.dll"
call %VSCOVERAGEPATH% analyze /output:report.xml "report.coverage"
call %sonarscanner% -Dsonar.cxx.vstest.reportsPaths="%~dp0\TestResults\report.trx"

call %sonarscanner% -X -Dsonar.cpp.cppdepend.projectPath="C:\Usersuser\OneDrive - Aspen Technology, Inc\Documents\CodeDemo.cdproj"
call %sonarscanner% -Dsonar.cxx.vscoveragexml.reportPaths="report.xml"
