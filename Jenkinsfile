pipeline {
    agent any

    stages {
        stage('Clone Repository') {
            steps {
                git branch: 'main', url: 'https://github.com/vinayp2219/ToDoList.git'
            }
        }

        stage('Build') {
            steps {
                echo 'Compiling C++ program...'
                bat 'g++ ToDoList.cpp -o todo'
            }
        }

        stage('Run') {
            steps {
                echo 'Running the C++ program...'
                bat './todo'
            }
        }
    }
}
