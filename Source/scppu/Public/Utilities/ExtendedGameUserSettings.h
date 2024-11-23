

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "ExtendedGameUserSettings.generated.h"

UENUM(BlueprintType)
enum class EUpscalerType : uint8
{
	None = 0 UMETA(DisplayName = "None"),
	FSR1 = 1 UMETA(DisplayName = "FSR 1"),
	FSR2 = 2 UMETA(DisplayName = "FSR 2"),
	DLSS3 = 3 UMETA(DisplayName = "DLSS 3.5"),
	//TAAU = 4 UMETA(DisplayName = "TAAU")
};

UENUM(BlueprintType)
enum class EUpscalerQualityMode : uint8
{
	Native = 0 UMETA(DisplayName = "Native"),
	Quality = 1 UMETA(DisplayName = "Quality"),
	Balanced = 2 UMETA(DisplayName = "Balanced"),
	Performance = 3 UMETA(DisplayName = "Performance"),
	UltraPerformance = 4 UMETA(DisplayName = "Ultra Performance")
};

UCLASS()
class SCPPU_API UExtendedGameUserSettings : public UGameUserSettings
{
	GENERATED_BODY()
	
	//// Properties ////
protected:
	UPROPERTY(config)
		EUpscalerType ActiveUpscaler = EUpscalerType::None;

	UPROPERTY(config)
		EUpscalerQualityMode UpscalerQualityMode = EUpscalerQualityMode::Quality;

	UPROPERTY(config)
		int ScreenPercentage = 100;

	// Gamma level to use. Higher value = more brightness
	UPROPERTY(config)
		float ScreenGammaLevel = 2.2f;

	// If true, Volumetric Fog will be used
	UPROPERTY(config)
	bool bUseVolumetric = true;

	// If true, texture streaming will be used
	UPROPERTY(config)
		bool bUseTextureStreaming = true;

	// if true, tesselation will be used (currently not working)
	UPROPERTY(config)
		bool bUseTessellation = true;

	// If true camera shakes can play
	UPROPERTY(config)
		bool bUseCameraShake = true;

	// Controls amount of viewbobbing
	UPROPERTY(config)
		float ViewBobStrength = 1.f;

	// Controls the FOV
	UPROPERTY(config)
		int FOV = 80;

	//// Functions ////	
public:
	// Returns the game local machine settings (resolution, windowing mode, scalability settings, etc...), but it's extended and has more settings
	UFUNCTION(BlueprintCallable, Category = Settings)
		static UExtendedGameUserSettings* GetExtendedGameUserSettings();

	UFUNCTION(BlueprintCallable, Category = Settings)
		TArray<EUpscalerType> GetSupportedUpscalers() const;

	UFUNCTION(BlueprintCallable, Category = Settings)
		void SetActiveUpscaler(EUpscalerType NewActiveUpscaler);

	UFUNCTION(BlueprintCallable, Category = Settings)
		EUpscalerType GetActiveUpscaler() const;

	UFUNCTION(BlueprintCallable, Category = Settings)
		void SetUpscalerQualityMode(EUpscalerQualityMode NewUpscalerQualityMode);

	UFUNCTION(BlueprintCallable, Category = Settings)
		EUpscalerQualityMode GetUpscalerQualityMode() const;

	// Sets the user setting for screen percentage as a 25..200 value
	UFUNCTION(BlueprintCallable, Category = Settings)
		void SetScreenPercentage(int Value);

	// Returns the user setting for screen percentage as a 25..200 value
	UFUNCTION(BlueprintCallable, Category = Settings)
		int GetScreenPercentage() const;

	// Sets the user setting for screen gamma as a 0.5f..5.0f value
	UFUNCTION(BlueprintCallable, Category = Settings)
		void SetScreenGamma(float Value);

	// Returns the user setting for screen gamma as a 0.5f..5.0f value
	UFUNCTION(BlueprintCallable, Category = Settings)
		float GetScreenGamma() const;

	// Returns the user setting for volumetric fog
	UFUNCTION(BlueprintCallable, Category = Settings)
	bool IsVolumetricFogEnabled() const;

	// Sets the user setting for Volumetric Fog
	UFUNCTION(BlueprintCallable, Category = Settings)
	void SetVolumetricFogEnabled(bool bEnabled);

	// Sets the user setting for texture streaming
	UFUNCTION(BlueprintCallable, Category = Settings)
		void SetTextureStreamingEnabled(bool bEnabled);

	// Returns the user setting for texture streaming
	UFUNCTION(BlueprintCallable, Category = Settings)
		bool IsTextureStreamingEnabled() const;

	// Sets the user setting for tessellation
	UFUNCTION(BlueprintCallable, Category = Settings, meta = (ToolTip = "!!! Disabling tessellation currently doesn't work and the option may be removed in the future !!!"))
		void SetTessellationEnabled(bool bEnabled);

	UFUNCTION(BlueprintCallable, Category = Settings, meta = (ToolTip = "!!! Disabling tessellation currently doesn't work and the option may be removed in the future !!!"))
		bool IsTessellationEnabled() const;

	// Sets if Camera shake such as from Elevators is enabled.
	UFUNCTION(BlueprintCallable, Category = "Settings | Gameplay")
		void SetCameraShakeEnabled(bool bEnabled);

	// Returns if Camera shake such as from Elevators is enabled.
	UFUNCTION(BlueprintCallable, Category = "Settings | Gameplay")
		bool IsCameraShakeEnabled() const;

	// Sets the user setting for how strong viewbob can be.
	UFUNCTION(BlueprintCallable, Category = "Settings | Gameplay")
		void SetViewbobStrength(float Value);

	// Returns the user setting for how strong viewbob can be.
	UFUNCTION(BlueprintCallable, Category = "Settings | Gameplay")
		float GetViewbobStrength() const;

	// Sets the user setting for FOV as a 10..130 value
	UFUNCTION(BlueprintCallable, Category = "Settings | Gameplay")
		void SetFOV(int Value);

	// Returns the user setting for FOV as a 10..130 value
	UFUNCTION(BlueprintCallable, Category = "Settings | Gameplay")
		int GetFOV() const;

	virtual void ApplyNonResolutionSettings() override;

protected:
	virtual void DisableAllUpscalers();
	virtual void EnableActiveUpscaler();
};
