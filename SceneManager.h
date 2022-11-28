#pragma once
#include <list>
#include <string>

enum SceneNo
{
	Title,
	NewGame,
	GamePlay,
	GameClear,
	Error,
};

class Scene
{
public:
	/// <summary>
	/// �V�[���N���X
	/// </summary>
	/// <param name="sceneStr">�\������V�[���̖��O</param>
	/// <param name="sceneNo">�V�[���̔ԍ�</param>
	Scene(std::string sceneStr,int sceneNo);

	std::string str;
	int sceneNo = Error;
};

class SceneManager
{
public:
	Scene *nowScene = nullptr;
	
	std::list<Scene> sceneList;

	void LoadScene(Scene scene);
	void ChangeScene(int sceneNo);

	static SceneManager *GetInstance();

private:
	SceneManager(){};
	~SceneManager(){};

	SceneManager(const SceneManager& a) = delete;
	SceneManager& operator=(const SceneManager&) = delete;
};

