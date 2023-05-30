pipeline {
	agent any
	//environment {
	//	LD_LIBRARY_PATH = '/usr/lib/x86_64-linux-gnu'
	//}
	stages {
		stage('BuildSamples') {
			steps {
				sh 'echo "Building sample tests"'
				sh 'chmod +x scripts/Linux-Build.sh'
				sh './scripts/Linux-Build.sh'
				// sh 'cd ./googletest/samples && make'
				archiveArtifacts artifacts: 'googletest/samples/*.exe', fingerprint: true
			}
		}
		stage('RunSampleTests') {
			// when {
            //   expression {
            //     currentBuild.result == null || currentBuild.result == 'SUCCESS' 
            //   }
            // }
			steps {
				sh 'echo "Running sample tests"'
				// sh 'chmod +x scripts/Linux-Run.sh' 
				sh 'cd googletest/samples/ && ./samples.exe'
			}
		}
		stage('Build') {
            steps {
                echo 'Building our main'
				sh 'cd ./main && make'
				archiveArtifacts artifacts: 'main/*.exe', fingerprint: true
            }
        }
		stage('Test') {
            steps {
                echo 'Test our functions'
				sh "cd ./main && ./tests.exe"
            }
        }
		stage('Run') {
			steps {
				echo 'Run our main'
				sh "cd ./main && ./main.exe ./CMakeLists.txt ./uppercase.txt"
			}
		}
		stage('Deploy') {
            steps {
                echo 'Deploying....(not implemented yet)'
            }
        }
		// post {
		// 	always {
		// 		junit '**/target/*.xml'
		// 	}
		// 	failure {
		// 		mail to: hello@example.com, subject: 'The Pipeline failed :('
		// 	}
		// }
	}
} 
