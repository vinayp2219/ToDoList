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
                // Define the JENKINS flag to avoid menu loop
                bat 'g++ -DJENKINS ToDoList.cpp -o todo.exe'
            }
        }

        stage('Run') {
            steps {
                echo 'Running the C++ program...'
                bat '.\\todo.exe'
            }
        }
    }
}
