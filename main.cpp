#include <Windows.h>
#include <d3d12.h>
#include <dxgi1_6.h>

#pragma comment(lib,"d3d12.lib")
#pragma comment(lib,"dxgi.lib")
#include <DirectXMath.h>
using namespace DirectX;
#include <d3dcompiler.h>
#pragma comment(lib,"d3dcompiler.lib")
#include <DirectXTex.h>
#include <iostream>
#include <memory>

//�����ŃN���X���������
#include "WinAPI.h"
#include "TimeManager.h"

#include "Result.h"
#include "Input.h"
#include "DirectXInit.h"
#include "Vertex.h"

#include "ViewProjection.h"
#include "Vector3.h"
#include "Texture.h"

#include "Sprite.h"
#include "Pipeline.h"
#include "ClearDrawScreen.h"
#include "Billboard.h"

#include "GameScene.h"

#include "Sound.h"
#include "DebugText.h"

#include "Particle.h"
#include "MathF.h"

#include "SceneManager.h"


//windows�A�v���ł̃G���g���[�|�C���g(main�֐�)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	///---DirectX�����������@��������---///
	
#ifdef  _DEBUG
//�f�o�b�O���C���[���I����
	ComPtr<ID3D12Debug1> debugController;
	if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&debugController)))) {
		debugController->EnableDebugLayer();
		//������O�Ƀf�o�C�X�𐶐�����ƃf�o�C�X���������炵��
		debugController->SetEnableGPUBasedValidation(TRUE);
	}

#endif _DEBUG

	WinAPI* winApi = WinAPI::GetInstance();
	DirectX12* DX12 = DirectX12::GetInstance();

#ifdef  _DEBUG
	ID3D12InfoQueue* infoQueue;
	if (SUCCEEDED(DX12->device->QueryInterface(IID_PPV_ARGS(&infoQueue)))) {
		infoQueue->GetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_CORRUPTION);//���o�C�G���[���ɂƂ܂�
		infoQueue->GetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_ERROR);	 //�G���[���Ɏ~�܂�
		infoQueue->Release();
	}
#endif  _DEBUG

	Input* input_ = Input::GetInstance();

	//DirectInput�̏�����
	input_->DirectInputInit();

	//�L�[�{�[�h�f�o�C�X�̐���
	input_->DirectInputCreate();

	///---DirectX�����������@�����܂�---///

	TimeManager::Init();

#pragma region �`�揉��������

	CreateDepthView();

	//�e�N�X�`���̃��[�h
	TextureManager::GetInstance()->Initialize();
	TextureManager::GetInstance()->PreLoad();

	SpriteCommon::spriteCommon.Initialize();

	ModelManager::GetInstance()->PreLoad();

	PipelineSet object3dPipelineSet = CreateObject3DPipeline();

	//�p�[�e�B�N���p�p�C�v���C������
	PipelineSet geometryObjectPipelineSet = CreateGeometryPipeline();

	//�f�o�b�O�e�L�X�g����

	std::unique_ptr<Texture> debugFont = std::make_unique<Texture>();
	debugFont->Load(L"Resources/debugfont.png");

	DebugText debugText;
	debugText.Initialize(debugFont.get());

	Obj3d skydome;
	skydome.Initialize();
	skydome.SetModel(&ModelManager::GetInstance()->skyDomeM);
	skydome.SetTexture(&TextureManager::GetInstance()->slime);

	//�r���[�ϊ��s��(�������e)���v�Z
	Camera *camera = Camera::camera;
	camera->Initialize();

	camera->target = {
		0,0,0
	};

	camera->SetEye({ 0,20,-10 });

#pragma endregion �`�揉��������

	SoundManager soundManager;
	soundManager.Initialize();

	SoundData curser = soundManager.SoundLoadWave("Resources\\sound\\curser.wav");

	//�Q�[�����[�v���Ŏg���ϐ��̐錾
	SceneManager* sceneManager = SceneManager::GetInstance();

	Scene Tscene("Title",Title);
	Scene Nscene("NewGame",NewGame);
	Scene Pscene("GamePlay",GamePlay);
	Scene Cscene("GameClear", GameClear);

	sceneManager->LoadScene(Tscene);
	sceneManager->LoadScene(Nscene);
	sceneManager->LoadScene(Pscene);
	sceneManager->LoadScene(Cscene);

	sceneManager->ChangeScene(Title);

	//�Q�[�����[�v
	while (true){

#pragma region �E�B���h�E���b�Z�[�W
		if (PeekMessage(&winApi->msg, nullptr, 0, 0, PM_REMOVE)) {
			TranslateMessage(&winApi->msg);		//�L�[���̓��b�Z�[�W�̏���
			DispatchMessage(&winApi->msg);		//�v���V�[�W���Ƀ��b�Z�[�W�𑗂�
		}

		if (winApi->msg.message == WM_QUIT) {
			break;
		}
#pragma endregion �E�B���h�E���b�Z�[�W

#pragma region DirectX���t���[������
		///---DirectX���t���[������ ��������---///
		
		ClearDrawScreen();

		//�X�V����

		input_->Update();

		camera->UpdatematView();
	
		if (input_->TriggerKey(DIK_SPACE))
		{
			if (sceneManager->nowScene->str == "GameClear")
			{
				sceneManager->ChangeScene(Title);
			}
			else if (sceneManager->nowScene->str == "Title")
			{
				sceneManager->ChangeScene(NewGame);
			}
			else if (sceneManager->nowScene->str == "NewGame")
			{
				sceneManager->ChangeScene(GamePlay);
			}
			else if (sceneManager->nowScene->str == "GamePlay")
			{
				sceneManager->ChangeScene(GameClear);
			}
		}

		//�I�u�W�F�N�g�̍X�V
		skydome.Update(camera->matView, camera->matProjection);

		debugText.Print(SpriteCommon::spriteCommon,
			"nowScene: " + sceneManager->nowScene->str, 50, 400);
		
		debugText.Print(SpriteCommon::spriteCommon,
			"Press SPACE to move to the next scene.", 50, 450);
		
		debugText.Print(SpriteCommon::spriteCommon,
			"Press ESCAPE to exit the application.", 50, 500);

		///---DirectX���t���[������ �����܂�---///
#pragma endregion DirectX���t���[������

#pragma region �O���t�B�b�N�X�R�}���h
		//--4.�`��R�}���h��������--//
		BasicObjectPreDraw( object3dPipelineSet);

		//�`�揈��
		skydome.DrawMaterial();

		GeometryObjectPreDraw(geometryObjectPipelineSet);
	
		//�X�v���C�g�̑O�`��(���ʃR�}���h)
		SpriteCommonBeginDraw(SpriteCommon::spriteCommon);

		//�X�v���C�g�P�̕`��
		debugText.DrawAll();

		//--4.�`��R�}���h�����܂�--//

#pragma endregion �O���t�B�b�N�X�R�}���h

#pragma region ��ʓ���ւ�

		PostDraw();

		debugText.PostDraw();

#pragma endregion ��ʓ���ւ�

		TimeManager::Update();

		if (input_->PushKey(DIK_ESCAPE))
		{
			break;
		}
	}

	//�����f�[�^�͐��xAudio2��������Ȃ���΂Ȃ�Ȃ�
	//xAudio2�̉��
	soundManager.End();

	//�����f�[�^�̉��
	soundManager.SoundUnload(&curser);

	//�E�B���h�E�N���X��o�^����
	UnregisterClass(winApi->w.lpszClassName, winApi->w.hInstance);

	return 0;
}