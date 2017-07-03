#include "StateMachine.h"
#include "Texture.h"
#include <GL/glew.h>

StateMachine::StateMachine()
{
	currentState = stateOneTeacherOrStudent;
}
StateMachine::~StateMachine() {}

const AppState StateMachine::getCurrentState() const
{
	return currentState;
}

void StateMachine::setCurrentState(AppState currState)
{
	currentState = currState;
}

void StateMachine::goToNextState(unsigned int mouseX, unsigned int mouseY, unsigned int windowWidth, unsigned int windowHeight)
{
	switch (currentState)
	{
		case stateOneTeacherOrStudent:
		{
			if (mouseY < windowHeight / 2)
			{
				Texture texture("G:/TU/TUT SEM8/Diplomna/Source/NEW/Clean/Pixio/Assets/AlOrGeo.png");
				glEnable(GL_TEXTURE_2D);
				currentState = stateStudentAlorGeo;
				texture.Bind(0);

			}
			else if (mouseY > windowHeight / 2)
			{
				Texture texture("G:/TU/TUT SEM8/Diplomna/Source/NEW/Clean/Pixio/Assets/Students.png");
				glEnable(GL_TEXTURE_2D);
				currentState = stateTeacher;
				texture.Bind(0);
			}
			else
			{
				// error case, mouse right in the middle
			}
			break;
		}
		case stateStudentAlorGeo:
		{
			if (mouseX < 95 && mouseY < 50)
			{
				Texture texture("G:/TU/TUT SEM8/Diplomna/Source/NEW/Clean/Pixio/Assets/TeacherStudent.png");
				glEnable(GL_TEXTURE_2D);
				currentState = stateOneTeacherOrStudent;
				texture.Bind(0);
			}
			else if (mouseY > windowHeight / 2)
			{
				Texture texture("G:/TU/TUT SEM8/Diplomna/Source/NEW/Clean/Pixio/Assets/numbers.png");
				glEnable(GL_TEXTURE_2D);
				currentState = stateProblemChoiseGeometry;
				texture.Bind(0);

			}
			else if (mouseY < windowHeight / 2)
			{
				Texture texture("G:/TU/TUT SEM8/Diplomna/Source/NEW/Clean/Pixio/Assets/numbers.png");
				glEnable(GL_TEXTURE_2D);
				currentState = stateProblemChoiseAlgebra;
				texture.Bind(0);
			}
			else
			{
				// error case, mouse right in the middle
			}
			break;
		}
		case stateTeacher:
		{
			if (mouseX < 95 && mouseY < 50)
			{
				Texture texture("G:/TU/TUT SEM8/Diplomna/Source/NEW/Clean/Pixio/Assets/TeacherStudent.png");
				glEnable(GL_TEXTURE_2D);
				currentState = stateOneTeacherOrStudent;
				texture.Bind(0);
			}
			else if (mouseY > windowHeight / 2)
			{
				Texture texture("G:/TU/TUT SEM8/Diplomna/Source/NEW/Clean/Pixio/Assets/Slavena.png");
				glEnable(GL_TEXTURE_2D);
				currentState = stateTeacherStudentInfo;
				texture.Bind(0);

			}
			else if (mouseY < windowHeight / 2)
			{
				Texture texture("G:/TU/TUT SEM8/Diplomna/Source/NEW/Clean/Pixio/Assets/Marina.png");
				glEnable(GL_TEXTURE_2D);
				currentState = stateTeacherStudentInfo;
				texture.Bind(0);
			}
			break;
		} 
		case stateTeacherStudentInfo:
		{
			Texture texture("G:/TU/TUT SEM8/Diplomna/Source/NEW/Clean/Pixio/Assets/Students.png");
			glEnable(GL_TEXTURE_2D);
			currentState = stateTeacher;
			texture.Bind(0);
			break;
		}
		case stateProblemChoiseAlgebra:
		{
			if (mouseX < 95 && mouseY < 50)
			{
				Texture texture("G:/TU/TUT SEM8/Diplomna/Source/NEW/Clean/Pixio/Assets/AlOrGeo.png");
				glEnable(GL_TEXTURE_2D);
				currentState = stateStudentAlorGeo;
				texture.Bind(0);
			}
			else
			{
				Texture texture("G:/TU/TUT SEM8/Diplomna/Source/NEW/Clean/Pixio/Assets/algebraProblem.png");
				glEnable(GL_TEXTURE_2D);
				texture.Bind(0);
				currentState = stateProblemAlgebra;
			}
			break;
		}
		case stateProblemChoiseGeometry:
		{
 			if (mouseX < 95 && mouseY < 50)
			{
				Texture texture("G:/TU/TUT SEM8/Diplomna/Source/NEW/Clean/Pixio/Assets/AlOrGeo.png");
				glEnable(GL_TEXTURE_2D);
				currentState = stateStudentAlorGeo;
				texture.Bind(0);
			}
			else
			{
				Texture texture("G:/TU/TUT SEM8/Diplomna/Source/NEW/Clean/Pixio/Assets/triangleProblem.png");
				glEnable(GL_TEXTURE_2D);
				texture.Bind(0);
				currentState = stateProblemGeometry;
			}
			break;
		}
		case stateProblemGeometry:
		{
			if (mouseX > windowWidth / 2)
			{
				Texture texture("G:/TU/TUT SEM8/Diplomna/Source/NEW/Clean/Pixio/Assets/bravofull.png");
				glEnable(GL_TEXTURE_2D);
				texture.Bind(0);
				currentState = stateCorrectGeometry;

			}
			else if (mouseX < windowWidth / 2)
			{
				Texture texture("G:/TU/TUT SEM8/Diplomna/Source/NEW/Clean/Pixio/Assets/tryAgainFull.png");
				glEnable(GL_TEXTURE_2D);
				texture.Bind(0);
				currentState = stateTryAgainGeometry;
			}
			else
			{
				// error case, mouse right in the middle
			}
			break;
		}
		case stateProblemAlgebra:
		{
			if (mouseX < windowWidth / 2)
			{
				Texture texture("G:/TU/TUT SEM8/Diplomna/Source/NEW/Clean/Pixio/Assets/bravofull.png");
				glEnable(GL_TEXTURE_2D);
				texture.Bind(0);
				currentState = stateCorrectAlgebra;

			}
			else if (mouseX > windowWidth / 2)
			{
				Texture texture("G:/TU/TUT SEM8/Diplomna/Source/NEW/Clean/Pixio/Assets/tryAgainFull.png");
				glEnable(GL_TEXTURE_2D);
				texture.Bind(0);
				currentState = stateTryAgainAlgebra;
			}
			else
			{
				// error case, mouse right in the middle
			}
			break;
		}
		case stateCorrectAlgebra:
		{
			Texture texture("G:/TU/TUT SEM8/Diplomna/Source/NEW/Clean/Pixio/Assets/numbers.png");
			glEnable(GL_TEXTURE_2D);
			texture.Bind(0);
			currentState = stateProblemChoiseAlgebra;
			break;
		}
		case stateCorrectGeometry:
		{
			Texture texture("G:/TU/TUT SEM8/Diplomna/Source/NEW/Clean/Pixio/Assets/numbers.png");
			glEnable(GL_TEXTURE_2D);
			texture.Bind(0);
			currentState = stateProblemChoiseGeometry;
			break;
		}
		case stateTryAgainAlgebra:
		{
			Texture texture("G:/TU/TUT SEM8/Diplomna/Source/NEW/Clean/Pixio/Assets/algebraProblem.png");
			glEnable(GL_TEXTURE_2D);
			texture.Bind(0);
			currentState = stateProblemAlgebra;
			break;
		}
		case stateTryAgainGeometry:
		{
			Texture texture("G:/TU/TUT SEM8/Diplomna/Source/NEW/Clean/Pixio/Assets/triangleProblem.png");
			glEnable(GL_TEXTURE_2D);
			texture.Bind(0);
			currentState = stateProblemGeometry;
			break;
		}
	}

}