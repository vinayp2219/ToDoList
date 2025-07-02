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
                echo 'Compiling C++ program...'
                sh 'g++ -o todo main.cpp'
            }
        }

        stage('Run') {
            steps {
                echo 'Running the C++ program...'
                sh './todo'
            }
        }
    }
}
