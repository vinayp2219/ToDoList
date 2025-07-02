pipeline {
    agent any

    stages {
        stage('Clone Repository') {
            steps {
                git 'https://github.com/vinayp2219/ToDoList.git'
            }
        }

        stage('Build') {
            steps {
                sh 'g++ ToDoList.cpp -o todo' // corrected: compile to an output binary named 'todo'
            }
        }

        stage('Test') {
            steps {
                echo 'No tests defined yet.'
                // Add test commands here if you use any test framework
            }
        }

        stage('Archive Binary') {
            steps {
                archiveArtifacts artifacts: 'todo', fingerprint: true // archive the compiled binary
            }
        }
    }
}
