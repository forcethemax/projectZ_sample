#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EHcAIActionType: uint8
{
	WAIT = 0 UMETA(Tooltip = "대기, 조건 체크"),
	MOVE_TO_AUTO_START_POS = 1 UMETA(Tooltip="자동 시작점으로 이동"),
	ATTACK_ANYONE = 2 UMETA(Tooltip="아무나 공격(찾기, 이동, 공격 한번에 처리)"),
	LOOT_ITEM = 3 UMETA(Tooltip="루팅"),
	INTERACTION = 4 UMETA(Tooltip="채집"),
	AUTO_MOVE_STOP = 5 UMETA(ToolTip="자동 이동 중지"),
	AUTO_MOVE_STOP_WITH_RESERVE_RETRY = 6 UMETA(Tooltip ="자동 이동 중지 및 reserve 재시도"),
	AUTO_MOVE_STOP_WITH_CLEAR_RESERVE_SKILL = 7 UMETA(Tooltip ="자동 이동 중지 및 예약된 skill clear"),
	WAIT_SECOND = 8 UMETA(Tooltip="특정시간동안 기다림"),
	LOOT_ITEM_AUTO_OFF = 9 UMETA(ToolTip="AUTO OFF 중(자동 이동중) 루팅(퀘스트 이동중 드롭한 아이템 획득)"),
	Max = 10,
};

UENUM(BlueprintType)
enum class EHcAIConditionType : uint8
{
	TARGET_EXIST = 0 UMETA(Tooltip="타겟이 있는지"),
	HAS_AUTO_RETURN_MODE = 1 UMETA(Tooltip="자동 복귀 상태인지"),
	IS_TOO_FAR_FROM_AUTO_START_POS = 2 UMETA(Tooltip="자동 시작점에서 너무 멀어졌는지"),
	IS_GAMEOBJ_FSM_IDLE = 3 UMETA(Tooltip="GameObj fsm 상태가 idle인지"),
	IS_IN_SEARCH_RANGE_ANYONE_ENEMY = 4 UMETA(Tooltip="시야내에 적이 있는지"),
	IS_IN_SEARCH_RANGE_ITEM = 5 UMETA(Tooltip="시야내에 아이템이 있는지"),
	IS_IN_SEARCH_RANGE_PROP = 6 UMETA(Tooltip="시야내에 채집 가능한 오브젝트가 있는지"),
	IS_QUEST_LAST_DROP_ITEM = 7 UMETA(Tooltip="퀘스트 진행 마지막 드롭 아이템이 있는지"),
	IS_GAMEOBJ_SKILL_USEABLE_STATE = 8 UMETA(Tooltip="스킬 사용가능한 상태인가(캔슬구간 or idle)"),
	IS_QUEST_AUTO_PLAY = 9 UMETA(Tooltip="퀘스트 오토 플레이중인가"),
	IS_COUNTER_ATTACK_ON = 10 UMETA(Tooltip="반격 옵션 ON 인가"),
	IS_COUNTER_ATTACK_TARGET_EXIST = 11 UMETA(Tooltip="반격 대상 있는가"),
	IS_AUTO_LOOT_COOL_TIME = 12 UMETA(Tooltip="오토 루팅 쿨타임(특정 행동에 의한 발동 ex)루팅 이동중에 1차 타게팅 or 땅찍고 이동)"),
	IS_QUEST_AUTO_LOOT = 13 UMETA(Tooltip="퀘스트 오토 채집인가"),
	IS_LOOT_SERVER_RESPONSE_WAIT = 14 UMETA(Tooltip="루팅 서버 응답 대기중인가"),
	IS_LOOT_IMPOSSIBLE = 15 UMETA(Tooltip="루팅 불가능한지( 무게 넘거나 인벤 슬롯 다차거나)"),
	IS_DIALOG_PLAY = 16 UMETA(Tooltip="대화 연출 중인지"),
	IS_INPUT_BLOCK = 17 UMETA(Tooltip="인풋이 막혀있는지"),
	IS_RESERVE_LOOTING = 18 UMETA(Tooltip="루팅 예약된 진행 정보가 있는지(진행중)"),
	IS_AUTO_RETURN_MOVE = 19 UMETA(Tooltip="사냥 거리 안으로 되돌아가기 이동인가"),
	IS_GAMEOBJ_FSM_AUTO_MOVE = 20 UMETA(Tooltip="자동 이동 상태인가"),
	IS_QUEST_CENTER_MOVE = 21 UMETA(Tooltip="퀘스트 중앙 이동중인가"),
	IS_STAY_LONG_TIME = 22 UMETA(Tooltip="한자리에서 오래 대기했는지"),
	IS_FIRST_JOB_RETRY = 23 UMETA(Tooltip="처음 JOB이 RETRY인지"),
	IS_SERVER_MOVE_LOCK = 24 UMETA(Tooltip="서버 이동 제한에 걸렸는지"),
	IS_ATTACKABLE = 25 UMETA(Tooltip="공격 가능한지"),
	IS_AUTO_RETURN_POSSIBLE_MAP = 26 UMETA(Tooltip="자동 회귀 가능한 맵인지"),
	IS_RESERVED_ACTION_AUTO_MOVE_STOP_WITH_CRS = 27 UMETA(Tooltip="자동 이동 중지 및 skill clear 액션 등록 되어있는지"),
	IS_MANUAL_INPUT_MOVE = 28 UMETA(Tooltip="수동 인풋에 의한 아동인지"),
	Max = 29,
};

UENUM(BlueprintType)
enum class EHcAIContentsType : uint8
{
	Field,				// 일반 필드
	Auto_off,			// 오토 꺼진 상태
};

enum class EHcAIDelayType : uint8
{
	NONE = 0,
	MAKE_JOB_DELAY = 1,
	RETRY_DELAY = 2,
};