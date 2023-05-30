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
			post {
				failure {
					script {
						currentBuild.result = 'FAILURE'
					}
				}
			}
		}
		stage('RunSampleTests') {
			when {
            	expression {
            		currentBuild.currentResult == 'SUCCESS' 
            	}
            }
			steps {
				echo "Running sample tests"
				// sh 'chmod +x scripts/Linux-Run.sh' 
				sh './googletest/samples/samples.exe'
			}
			post {
				always {
					script {
						currentBuild.result = 'SUCCESS'
					}
				}
			}
		}
		stage('Build') {
            steps {
                echo 'Building our main'
				sh 'chmod u+x scripts/OurMain-Build.sh'
				sh './scripts/OurMain-Build.sh'
				archiveArtifacts artifacts: '*', fingerprint: true
            }
			post {
				failure {
					script {
						currentBuild.result = 'FAILURE'
					}
				}
			}
        }
		stage('Test') {
			when {
            	expression {
            		currentBuild.currentResult == 'SUCCESS' 
            	}
            }
            steps {
                echo 'Test our functions'
				sh "./main/tests.exe"
            }
			post {
				failure {
					script {
						currentBuild.result = 'FAILURE'
					}
				}
			}
        }
		stage('Run') {
			when {
            	expression {
            		currentBuild.currentResult == 'SUCCESS' 
            	}
            }
			steps {
				echo 'Run our main'
				sh "./main/main.exe ./main/inputText.txt ./main/uppercaseText.txt"
			}
		}
		stage('Deploy') {
			when {
            	expression {
            		currentBuild.currentResult == 'SUCCESS' 
            	}
            }
            steps {
                echo 'Deploying....(not implemented yet)'
            }
        }
	}
	post {
		always {
			echo 'One way or another, I have finished'
			deleteDir() /* clean up our workspace */
		}
		success {
			slackSend failOnError: true, 
				message: "I see, I see. Good job guys! - ${env.JOB_NAME} ${env.BUILD_NUMBER} (<${env.BUILD_URL}|Open>)"
		}
		failure {
			slackSend failOnError: true,
				message: "I don't see, I don't see. Something went wrong - ${env.JOB_NAME} ${env.BUILD_NUMBER} (<${env.BUILD_URL}|Open>)"
		}
	}
} 
