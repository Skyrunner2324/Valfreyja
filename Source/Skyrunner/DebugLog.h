#pragma once

#define DebugLog(seconds, color, ...) GEngine->AddOnScreenDebugMessage(-1, seconds, color, FString::Printf(__VA_ARGS__))

#define DebugLogRed(...) DebugLog(15.f, FColor::Red, __VA_ARGS__)
#define DebugLogGreen(...) DebugLog(15.f, FColor::Green, __VA_ARGS__)
#define DebugLogBlue(...) DebugLog(15.f, FColor::Cyan, __VA_ARGS__)

#define DebugLogPerFrame(color, ...) DebugLog(DeltaTime, color, __VA_ARGS__)

#define DebugLogVector(v) DebugLogRed(TEXT("%f, %f, %f"), v.X, v.Y, v.Z);