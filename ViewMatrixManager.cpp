#include "pch.h"

ViewMatrixManager* g_pViewMatrixManager = new ViewMatrixManager();
ViewMatrixManager::ViewMatrixManager() {}
ViewMatrixManager::~ViewMatrixManager() {}

void ViewMatrixManager::worldToScreen(Vector3f pos, Vector3f& screen, float* distance, int* distanceValue)
{
	float screenW = (viewmatrix._14 * pos.x) + (viewmatrix._24 * pos.y) + (viewmatrix._34 * pos.z + viewmatrix._44);
	screen.z = screenW;
	if (distance != nullptr)
	{
		*distance = screenW;
	}
	if (distanceValue != nullptr)
	{
		*distanceValue = (int)(screenW / 100);
	}
	screenW = 1.f / screenW;
	float sightX = (float)(g_pOverlay->width / 2.f);
	float sightY = (float)(g_pOverlay->height / 2.f);
	screen.x = sightX + (viewmatrix._11 * pos.x + viewmatrix._21 * pos.y + viewmatrix._31 * pos.z + viewmatrix._41) * screenW * sightX;
	screen.y = sightY - (viewmatrix._12 * pos.x + viewmatrix._22 * pos.y + viewmatrix._32 * pos.z + viewmatrix._42) * screenW * sightY;
}

void ViewMatrixManager::worldBoneToScreen(Vector3f pos, Vector3f& screen)
{
	float screenW = (viewmatrix._14 * pos.x) + (viewmatrix._24 * pos.y) + (viewmatrix._34 * pos.z + viewmatrix._44);
	screen.z = screenW;
	screenW = 1 / screenW;
	float sightX = (float)(g_pOverlay->width / 2.f);
	float sightY = (float)(g_pOverlay->height / 2.f);
	screen.x = sightX + (viewmatrix._11 * pos.x + viewmatrix._21 * pos.y + viewmatrix._31 * pos.z + viewmatrix._41) * screenW * sightX;
	screen.y = sightY - (viewmatrix._12 * pos.x + viewmatrix._22 * pos.y + viewmatrix._32 * pos.z + viewmatrix._42) * screenW * sightY;
}
