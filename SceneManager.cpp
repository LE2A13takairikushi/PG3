#include "SceneManager.h"

void SceneManager::LoadScene(Scene scene)
{
	sceneList.emplace_back(scene);
}

void SceneManager::ChangeScene(int sceneNo)
{
	for (Scene& scene : sceneList)
	{
		if (scene.sceneNo == sceneNo)
		{
			nowScene = &scene;
			break;
		}
	}
}

SceneManager *SceneManager::GetInstance()
{
	static SceneManager instance;
	return &instance;
}

Scene::Scene(std::string str, int sceneNo)
{
	this->str = str;
	this->sceneNo = sceneNo;
}