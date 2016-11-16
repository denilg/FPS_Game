// Fill out your copyright notice in the Description page of Project Settings.

#include "FPS_Game.h"
#include "../Public/ChooseNextWaypoint.h"
#include "AIController.h"
#include "../Public/PatrolRoute.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{

	// TODO protect against empty patrol routes


	// get the patrol points
	//auto AIController = OwnerComp.GetAIOwner();
	//auto ControlledPawn = AIController->GetPawn();
	auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();

	if (!ensure(PartolRoute)) { return EBTNodeResult::Failed; }

	// warn about empty patrol routes
	auto PatrolPoints = PatrolRoute->GetPatrolPoints();
	if (PatrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning,TEXT("A guard is missing patrol points"))
		return EBTNodeResult::Failed;
	}

	// set next waypoint
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);

	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	//Cycle the index
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);

	return EBTNodeResult::Succeeded;
}
