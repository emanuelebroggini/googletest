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
				sh 'chmod u+x scripts/Linux-Run.sh'
				sh './scripts/Linux-Run.sh'
				// script {
                //     def exitCode = sh './googletest/samples/samples.exe', returnStatus: true
				// 	// echo exitCode
                //     if (exitCode != 0) {
                //         currentBuild.result = 'FAILURE'
                //     }else {
				// 		currentBuild.result = 'SUCCESS'
				// 	}
                // }
			}
		}
		stage('Build') {
			when {
            	expression {
            		currentBuild.currentResult == 'SUCCESS' 
            	}
            }
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
			agent { node { label 'deploy' } } // nell'istanza del nodo deploy installare docker!
			steps {
				//sh 'mkdir main/docker && pwd'
				//sh 'pwd'
				// sh '-v $(which docker) :/usr/bin/docker'
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
            steps {
				sh 'docker login -u leobeltra -p ratto8080'
                sh 'docker push leobeltra/sweng4hpc'
			}
		}
	}
	post {
		always {
			echo 'One way or another, I have finished. Clean up our workspace'
			deleteDir() /* clean up our workspace */
		}
		success {
			slackSend failOnError: true, 
				message: "I see, I see. Good job guys! - ${env.JOB_NAME} ${env.BUILD_NUMBER} (<${env.BUILD_URL}|Open>)\nIt took ${currentBuild.durationString}"
		}
		failure {
			slackSend failOnError: true,
				message: "I don't see, I don't see. Something went wrong - ${env.JOB_NAME} ${env.BUILD_NUMBER} (<${env.BUILD_URL}|Open>)"
		}
	}
} 
