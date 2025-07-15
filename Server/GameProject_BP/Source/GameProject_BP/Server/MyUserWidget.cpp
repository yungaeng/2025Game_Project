// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidget.h"

void UMyUserWidget::NativeConstruct()
{
    Super::NativeConstruct();

    // 버튼 클릭 이벤트 바인딩
    if (Signin)
    {
        Signin->OnClicked.AddDynamic(this, &UMyUserWidget::OnSignInButtonClicked);
    }
    if (Login)
    {
        Login->OnClicked.AddDynamic(this, &UMyUserWidget::OnLoginButtonClicked);
    }
    if (Disconnecting)
    {
        Disconnecting->OnClicked.AddDynamic(this, &UMyUserWidget::OnDisconnectButtonClicked);
    }

    // EditableTextBox의 텍스트 변경 이벤트 바인딩
    if (nameedit)
    {
        nameedit->OnTextChanged.AddDynamic(this, &UMyUserWidget::OnEditableNameChanged);
    }
    if (serveripedit)
    {
        serveripedit->OnTextChanged.AddDynamic(this, &UMyUserWidget::OnEditableServeripChanged);
    }

    // 다른 위젯 이벤트 바인딩...
}

void UMyUserWidget::OnSignInButtonClicked()
{
    // Signin 버튼 클릭 시 로직 (위젯 블루프린트의 해당 이벤트 노드 참고)
    UE_LOG(LogTemp, Warning, TEXT("Sign In 버튼 클릭됨!"));
    // Set Text나 다른 노드들의 기능을 여기에 구현합니다.
    // 예를 들어, Text->SetText(FText::FromString(TEXT("로그인 시도 중...")));
}

void UMyUserWidget::OnLoginButtonClicked()
{
    // Login 버튼 클릭 시 로직
    UE_LOG(LogTemp, Warning, TEXT("Login 버튼 클릭됨!"));
    // Get Text 후 다른 로직으로 연결
    if (nameedit)
    {
        FString UserName = nameedit->GetText().ToString();
        UE_LOG(LogTemp, Warning, TEXT("사용자 이름: %s"), *UserName);
    }
    if (serveripedit)
    {
        FString serverip = serveripedit->GetText().ToString();
        UE_LOG(LogTemp, Warning, TEXT("서버 주소: %s"), *serverip);
    }
}

void UMyUserWidget::OnDisconnectButtonClicked()
{
    // Disconnect 버튼 클릭 시 로직
    UE_LOG(LogTemp, Warning, TEXT("Disconnect 버튼 클릭됨!"));
}

void UMyUserWidget::OnEditableNameChanged(const FText& InText) // 변경된 부분
{
    // EditableTextBox 텍스트 변경 시 로직
    UE_LOG(LogTemp, Warning, TEXT("EditableTextBox 텍스트 변경됨: %s"), *InText.ToString());
}

void UMyUserWidget::OnEditableServeripChanged(const FText& InText_202) // 변경된 부분
{
    // EditableTextBox_202 텍스트 변경 시 로직 (Server IP)
    UE_LOG(LogTemp, Warning, TEXT("Server IP 텍스트 변경됨: %s"), *InText_202.ToString());
}

