#include "MyGameInstance.h"
#include "Engine/World.h"

void UMyGameInstance::Init()
{
	// Initialize the path with predefined points, resizing it based on PathSize
	Path = {
		FVector2D(208.538, -2207.572),
		FVector2D(1111.495, -947.133),
		FVector2D(1200.725, 758.269),
		FVector2D(341.294, 1350.226),
		FVector2D(388.244, 2284.599),
		FVector2D(-313.202, 2865.887),
		FVector2D(-1212.458, 2299.131),
		FVector2D(-1095.787, 1336.131),
		FVector2D(-508.744, 744.174),
		FVector2D(-532.226, 194.499),
		FVector2D(-959.593, -139.064),
		FVector2D(-1565.421, -439.742),
		FVector2D(-1537.243, -1275.999),
		FVector2D(-674.235, -1669.881),
		FVector2D(-656.067, -2846.988)
	};

	// Trim the path to respect the PathSize
	if (Path.Num() > PathSize)
	{
		Path.SetNum(PathSize);
	}
}

UMyGameInstance* UMyGameInstance::GetMyGameInstance(UWorld* World)
{
	if (!World)
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid World pointer!"));
		return nullptr;
	}

	UMyGameInstance* MyGameInstance = Cast<UMyGameInstance>(World->GetGameInstance());

	ensureMsgf(MyGameInstance != nullptr, TEXT("Unable to find GameInstance!"));
	return MyGameInstance;
}
