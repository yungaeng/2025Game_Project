// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h" // 버튼 컴포넌트를 사용하기 위해 포함
#include "Components/EditableTextBox.h" // 에디터블 텍스트 박스 컴포넌트를 사용하기 위해 포함
#include "Components/TextBlock.h" // 텍스트 블록 컴포넌트를 사용하기 위해 포함
#include "MyUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROJECT_BP_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
    // BeginPlay와 유사하게 위젯이 생성될 때 호출되는 함수
    virtual void NativeConstruct() override;

protected:
    // UI 요소들 (UPROPERTY(meta=(BindWidget))을 통해 위젯 블루프린트의 이름과 연결)
    UPROPERTY(meta = (BindWidget))
    UTextBlock* signintext; // "테스트" 텍스트블록에 해당

    UPROPERTY(meta = (BindWidget))
    UTextBlock* logintext; // "부울" 텍스트블록에 해당

    UPROPERTY(meta = (BindWidget))
    UButton* Signin;

    UPROPERTY(meta = (BindWidget))
    UButton* Login;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* nametext;

    UPROPERTY(meta = (BindWidget))
    UEditableTextBox* nameedit; // Name에 해당

    UPROPERTY(meta = (BindWidget))
    UTextBlock* serveriptext;

    UPROPERTY(meta = (BindWidget))
    UEditableTextBox* serveripedit; // Server IP에 해당

    UPROPERTY(meta = (BindWidget))
    UButton* Disconnecting;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* disconnecttext;


    // 이벤트 처리 함수
    UFUNCTION()
    void OnSignInButtonClicked();

    UFUNCTION()
    void OnLoginButtonClicked();

    UFUNCTION()
    void OnDisconnectButtonClicked();

    UFUNCTION()
    void OnEditableNameChanged(const FText& Text); // EditableTextBox의 텍스트 변경 시

    UFUNCTION()
    void OnEditableServeripChanged(const FText& Text); // EditableTextBox_202의 텍스트 변경 시

    // 다른 이벤트 처리 함수들... (위젯 블루프린트의 이벤트 그래프를 참고하여 추가)
    // 예를 들어, Input Text Changed (Committed) 이벤트도 고려할 수 있습니다.
};

