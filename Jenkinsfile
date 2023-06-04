pipeline {
	agent any
	stages {
		stage('BuildSamples') {
			agent { node { label 'build'} }
			steps {
				echo "Building sample tests"
				sh 'chmod +x scripts/Linux-Build.sh'
				sh './scripts/Linux-Build.sh'
				archiveArtifacts artifacts: 'googletest/samples/sample*.exe', fingerprint: true
				stash includes: 'googletest/samples/sample*.exe', name: 'tests'
			}
		}
		stage('Test') {
			when {
            	expression {
            		currentBuild.currentResult == 'SUCCESS' 
            	}
            }
			steps {
				echo "Running sample tests"
				unstash 'tests'
				sh 'chmod u+x scripts/Linux-Run.sh'
				sh './scripts/Linux-Run.sh'
			}
		}
		stage('Build') {
			when {
            	expression {
            		currentBuild.currentResult == 'SUCCESS' 
            	}
            }
			agent { node { label 'build'} }
            steps {
                echo 'Building our main'
				sh 'chmod u+x scripts/OurMain-Build.sh'
				sh './scripts/OurMain-Build.sh'
				stash includes: 'main/main.exe', name: 'our exe'
				archiveArtifacts artifacts: 'main/main.exe', fingerprint: true
            }
        }
		stage('Run') {
			when {
            	expression {
            		currentBuild.currentResult == 'SUCCESS' 
            	}
            }
			steps {
				unstash 'our exe'
				echo 'Run our main'
				sh "./main/main.exe ./main/inputText.txt ./main/uppercaseText.txt"
				sh "less ./main/uppercaseText.txt"
			}
		}
		stage('CreateDockerImage'){
			when {
            	expression {
            		currentBuild.currentResult == 'SUCCESS' 
            	}
            }
			agent { node { label 'deploy' } }
			steps {
				unstash 'our exe'
                sh 'docker build -t leobeltra/sweng4hpc .'
            }
		}
	    stage('PushDockerImage') {
			when {
            	expression {
            		currentBuild.currentResult == 'SUCCESS' 
            	}
            }
			agent { node { label 'deploy' } }
			environment {
				DKRHUB_CREDS = credentials('DockerHub_credentials')
			}
            steps {
				sh 'docker login -u $DKRHUB_CREDS_USR -p $DKRHUB_CREDS_PSW' // use single quotes here to hide usr and psw
                sh 'docker push leobeltra/sweng4hpc'
			}
			post {
				always{
					sh 'docker logout'
				}
			}
		}
	}
	post {
		always {
			echo 'One way or another, I have finished. Clean up our workspace'
			deleteDir() /* clean up our workspace */
		}
		success {
			slackSend color: "good", failOnError: true, message: "I see, I see. Good job guys! - ${env.JOB_NAME} ${env.BUILD_NUMBER} (<${env.BUILD_URL}|Open>)\nIt took ${currentBuild.durationString}"
		}
		failure {
			slackSend color: "danger", failOnError: true, message: "I don't see, I don't see. Something went wrong - ${env.JOB_NAME} ${env.BUILD_NUMBER} (<${env.BUILD_URL}|Open>)"
		}
	}
} 
