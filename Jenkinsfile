pipeline {
	agent any
	//environment {
	//	LD_LIBRARY_PATH = '/usr/lib/x86_64-linux-gnu'
	//}
	stages {
		stage('BuildSamples') {
			steps {
				echo "Building sample tests"
				sh 'chmod +x scripts/Linux-Build.sh'
				sh './scripts/Linux-Build.sh'
				// sh 'cd ./googletest/samples && make' this is not working
				archiveArtifacts artifacts: '*', fingerprint: true
			}
		}
		stage('RunSampleTests') {
			// when {
            //   expression {
            //     currentBuild.result == null || currentBuild.result == 'SUCCESS' 
            //   }
            // }
			steps {
				echo "Running sample tests"
				// sh 'chmod +x scripts/Linux-Run.sh' 
				sh './googletest/samples/samples.exe'
			}
		}
		stage('Build') {
            steps {
                echo 'Building our main'
				sh 'chmod u+x scripts/OurMain-Build.sh'
				sh './scripts/OurMain-Build.sh'
				archiveArtifacts artifacts: '*', fingerprint: true
            }
        }
		stage('Test') {
            steps {
                echo 'Test our functions'
				sh "./main/tests.exe"
            }
        }
		stage('Run') {
			steps {
				echo 'Run our main'
				sh "./main/main.exe ./main/inputText.txt ./main/uppercaseText.txt"
			}
		}
		stage('Deploy') {
            steps {
                echo 'Deploying....(not implemented yet)'
            }
        }
		post {
		 	success {
		 		slackSend failOnError: true, message: "Good job guys! - ${env.JOB_NAME} ${env.BUILD_NUMBER} (<${env.BUILD_URL}|Open>)"
		 	}
		 	failure {
		 		slackSend failOnError: true, message: "Something went wrong - ${env.JOB_NAME} ${env.BUILD_NUMBER} (<${env.BUILD_URL}|Open>)"
		 	}
		}
	}
} 
