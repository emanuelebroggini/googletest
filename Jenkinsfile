pipeline {
	agent any
	stages {
		stage('Build') {
			steps {
				sh 'echo "Building..."'
				sh 'chmod +x scripts/Linux-Build.sh' 
				sh 'chmod +x googletest/samples/*'
				sh 'pwd'
				sh 'ls'
				sh 'cd googletest'
				sh 'scripts/Linux-Build.sh'
				archiveArtifacts artifacts: '*', fingerprint: true
			}
		}
		stage('Test') {
			steps {
				sh 'echo "Running..."'
				sh 'chmod +x scripts/Linux-Run.sh' 
				sh 'scripts/Linux-Run.sh'  
			}
		}
	}
}
