#pragma once

#include "Packet.h"

/*
 *	��ȯ â ����
 */
class CPythonExchange : public CSingleton<CPythonExchange>
{
	public:
		enum
		{
			EXCHANGE_ITEM_MAX_NUM = 24,
		};

		typedef struct trade
		{
			char					name[CHARACTER_NAME_MAX_LEN + 1];

			DWORD					item_vnum[EXCHANGE_ITEM_MAX_NUM];
			short					item_count[EXCHANGE_ITEM_MAX_NUM];
			DWORD					item_metin[EXCHANGE_ITEM_MAX_NUM][ITEM_SOCKET_SLOT_MAX_NUM];
			TPlayerItemAttribute	item_attr[EXCHANGE_ITEM_MAX_NUM][ITEM_ATTRIBUTE_SLOT_MAX_NUM];

			BYTE					accept;
			long long				elk;
			DWORD					race;
			DWORD					level;
		} TExchangeData;

	public:
		CPythonExchange();
		virtual ~CPythonExchange();

		void			Clear();

		void			Start();
		void			End();
		bool			isTrading();

		// Interface

		void			SetSelfName(const char *name);
		void			SetTargetName(const char *name);

		char			*GetNameFromSelf();
		char			*GetNameFromTarget();

		void			SetElkToTarget(long long elk);
		void			SetElkToSelf(long long elk);

		long long		GetElkFromTarget();
		long long		GetElkFromSelf();
		
		void			SetSelfRace(DWORD race);
		void			SetTargetRace(DWORD race);
		
		DWORD			GetRaceFromSelf();
		DWORD			GetRaceFromTarget();
		
		void			SetSelfLevel(DWORD level);
		void			SetTargetLevel(DWORD level);
		
		DWORD			GetLevelFromSelf();
		DWORD			GetLevelFromTarget();
				
		void			SetItemToTarget(DWORD pos, DWORD vnum, short count);
		void			SetItemToSelf(DWORD pos, DWORD vnum, short count);

		void			SetItemMetinSocketToTarget(int pos, int imetinpos, DWORD vnum);
		void			SetItemMetinSocketToSelf(int pos, int imetinpos, DWORD vnum);

		void			SetItemAttributeToTarget(int pos, int iattrpos, BYTE byType, short sValue);
		void			SetItemAttributeToSelf(int pos, int iattrpos, BYTE byType, short sValue);

		void			DelItemOfTarget(BYTE pos);
		void			DelItemOfSelf(BYTE pos);

		DWORD			GetItemVnumFromTarget(BYTE pos);
		DWORD			GetItemVnumFromSelf(BYTE pos);

		short			GetItemCountFromTarget(BYTE pos);
		short			GetItemCountFromSelf(BYTE pos);

		DWORD			GetItemMetinSocketFromTarget(BYTE pos, int iMetinSocketPos);
		DWORD			GetItemMetinSocketFromSelf(BYTE pos, int iMetinSocketPos);

		void			GetItemAttributeFromTarget(BYTE pos, int iAttrPos, BYTE * pbyType, short * psValue);
		void			GetItemAttributeFromSelf(BYTE pos, int iAttrPos, BYTE * pbyType, short * psValue);

		void			SetAcceptToTarget(BYTE Accept);
		void			SetAcceptToSelf(BYTE Accept);

		bool			GetAcceptFromTarget();
		bool			GetAcceptFromSelf();

		bool			GetElkMode();
		void			SetElkMode(bool value);

	protected:
		bool				m_isTrading;

		bool				m_elk_mode;   // ��ũ�� Ŭ���ؼ� ��ȯ�������� ���� ������.
		TExchangeData		m_self;
		TExchangeData		m_victim;
};
