#pragma once

#include "Subsystems/EngineSubsystem.h"
#include "UnrealVolcEngineSubsystem.generated.h"

class IWebSocket;
class USoundWaveProcedural;
class UAudioComponent;
namespace Audio { class FAudioCapture; }

UCLASS()
class UNREALVOLCENGINERUNTIME_API UUnrealVolcEngineSubsystem : public UEngineSubsystem {
    GENERATED_BODY()
public:
    static UUnrealVolcEngineSubsystem* Get();

    void StartListening(int AutoStopTimeoutSec);

    void StopListening();

    void Ask(FString Message, TFunction<void(FString Response)> Callback);

    UFUNCTION(BlueprintCallable)
    void Speak(UObject* WorldContextObject, FString Text);

protected:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    void OnAudioCapture(const void* AudioData, int32 NumFrames, int32 InNumChannels, int32 InSampleRate, double StreamTime, bool bOverFlow);

    void TryFlushWorld(UWorld* InWorld);
    void OnConnected();
    void OnConnectionError(const FString& Error);
    void OnClosed(int32 StatusCode, const FString& Reason, bool bWasClean);
    void OnMessage(const FString& Message);
    void OnMessageRaw(const void* Data, SIZE_T Size, SIZE_T BytesRemaining);
    bool ParseResponse(const TArray<uint8>& Res);
private:
    TSharedPtr<Audio::FAudioCapture> AudioCapture;

    TSharedPtr<IWebSocket> WebSocket;
    TArray<uint8> DefaultHeader = { 0x11, 0x10, 0x11, 0x00 };
    TArray<uint8> NetBuffer;
    FString PendingSpeakText;

    TObjectPtr<UWorld> CurrentWorld;

    UPROPERTY()
    TObjectPtr<USoundWaveProcedural> WaveProcedural;

    UPROPERTY()
    TObjectPtr<UAudioComponent> WaveProceduralAudioComponent;
};