#pragma once

#include "Packet.h"

/*
 *	���� ó��
 *
 *	2003-01-16 anoa	���� �Ϸ�
 *	2003-12-26 levites ����
 *
 *	2012-10-29 rtsummit ���ο� ȭ�� ���� �� tab ��� �߰��� ���� shop Ȯ��.
 *
 */
typedef enum
{
	SHOP_COIN_TYPE_GOLD, // DEFAULT VALUE
	SHOP_COIN_TYPE_SECONDARY_COIN,
} EShopCoinType;

typedef enum
{
	SHOP_TYPE_GOLD,	// DEFULT VALUE
	SHOP_TYPE_CASH,	// account.cash
	SHOP_TYPE_COINS,	// account.coins
	SHOP_TYPE_ALIGN,	// player.alignment
} EShopType;

class CPythonShop : public CSingleton<CPythonShop>
{
	public:
		CPythonShop(void);
		virtual ~CPythonShop(void);

		void Clear();
		
		void SetItemData(DWORD dwIndex, const TShopItemData & c_rShopItemData);
		BOOL GetItemData(DWORD dwIndex, const TShopItemData ** c_ppItemData);

		void SetItemData(BYTE tabIdx, DWORD dwSlotPos, const TShopItemData & c_rShopItemData);
		BOOL GetItemData(BYTE tabIdx, DWORD dwSlotPos, const TShopItemData ** c_ppItemData);
		
		void SetTabCount(BYTE bTabCount) { m_bTabCount = bTabCount; }
		BYTE GetTabCount() { return m_bTabCount; }

		void SetTabCoinType(BYTE tabIdx, BYTE coinType);
		BYTE GetTabCoinType(BYTE tabIdx);

		void SetTabName(BYTE tabIdx, const char* name);
		const char* GetTabName(BYTE tabIdx);

		void SetShopName(const char* name);
		void SetPriceType(short price_type);
		const char* GetShopName();
		short GetPriceType();
		//BOOL GetSlotItemID(DWORD dwSlotPos, DWORD* pdwItemID);

		void Open(BOOL isPrivateShop, BOOL isMainPrivateShop);
		void Close();
		BOOL IsOpen();
		BOOL IsPrivateShop();
		BOOL IsMainPlayerPrivateShop();

		void ClearPrivateShopStock();
		void AddPrivateShopItemStock(TItemPos ItemPos, BYTE byDisplayPos, long long dwPrice);
		void DelPrivateShopItemStock(TItemPos ItemPos);
		long long GetPrivateShopItemPrice(TItemPos ItemPos);
		void BuildPrivateShop(const char * c_szName);
		
	protected:
		BOOL	CheckSlotIndex(DWORD dwIndex);

	protected:
		BOOL				m_isShoping;
		BOOL				m_isPrivateShop;
		BOOL				m_isMainPlayerPrivateShop;

		struct ShopTab
		{
			ShopTab()
			{
				coinType = SHOP_COIN_TYPE_GOLD;
			}
			BYTE				coinType;
			std::string			name;
			TShopItemData		items[SHOP_HOST_ITEM_MAX_NUM];
		};
		
		std::string			shop_name;
		short				sPrice_type;
		
		BYTE m_bTabCount;
		ShopTab m_aShoptabs[SHOP_TAB_COUNT_MAX];

		typedef std::map<TItemPos, TPrivateShopItemTable> TPrivateShopItemStock;
		TPrivateShopItemStock	m_PrivateShopItemStock;
};
