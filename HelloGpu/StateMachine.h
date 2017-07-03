#pragma once

enum AppState
{
	stateOneTeacherOrStudent,
	stateStudentAlorGeo,
	stateTeacher,
	stateTeacherStudentInfo,
	stateProblemChoiseAlgebra,
	stateProblemChoiseGeometry,
	stateProblemAlgebra,
	stateProblemGeometry,
	stateCorrectAlgebra,
	stateCorrectGeometry,
	stateTryAgainAlgebra,
	stateTryAgainGeometry
};

class StateMachine
{
public:
	StateMachine();
	~StateMachine();

	const AppState getCurrentState() const;
	void setCurrentState(const AppState currState);
	void goToNextState(unsigned int mouseX, unsigned int mouseY, unsigned int windowWidth, unsigned int windowHeight);

private:
	AppState currentState;

};