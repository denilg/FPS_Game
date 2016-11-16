// Fill out your copyright notice in the Description page of Project Settings.

#include "FPS_Game.h"
#include "../Public/PatrolRoute.h"


TArray<AActor*> UPatrolRoute::GetPatrolPoints() const
{
	return PatrolPoints;
}

