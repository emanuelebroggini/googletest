pipeline {
	agent any
	environment {
		LD_LIBRARY_PATH = '/usr/lib'
    	}
	stages {
		stage('Build') {
			steps {
				sh 'echo "Building..."'
				sh 'chmod +x scripts/Linux-Build.sh' 
				// sh 'chmod +x googletest/samples/*'
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
