/*
	Use this to print a message on the screen!
*/

#pragma once

#include <wchar.h>
#include <ASMMacros.h>
#include <ColorScheme.h>
#include <CommandClass.h>

#include <Helpers/CompileTime.h>

#include <LinkClass.h>

enum class KeyModifier : int
{
	None = 0,
	Shift = 1,
	Ctrl = 2,
	Alt = 4
};

enum class GadgetFlag : int
{
	LeftPress = 0x1,
	LeftHeld = 0x2,
	LeftRelease = 0x4,
	LeftUp = 0x8,
	RightPress = 0x10,
	RightHeld = 0x20,
	RightRelease = 0x40,
	RightUp = 0x80,
	Keyboard = 0x100
};

enum class TextPrintType : int
{
	LASTPOINT = 0x0, //*
	LASTSHADOW = 0x0, //*
	Point6 = 0x1, //*
	Point8 = 0x2,
	Point3 = 0x3, //*
	Led = 0x4, //*
	Vcr = 0x5, //*
	Point6Grad = 0x6,
	Map = 0x7, //*
	Metal12 = 0x8,
	Efnt = 0x9, //*
	Type = 0xA, //*
	Score = 0xB, //*
	Fonts = 0xF, //*
	NoShadow = 0x10,
	DropShadow = 0x20,
	FullShadow = 0x40,
	LightShadow = 0x80,
	Center = 0x100,
	Right = 0x200,
	Background = 0x400,
	MediumColor = 0x1000,
	BrightColor = 0x2000,
	UseGradPal = 0x4000,
	UnknownColor = 0x8000,
	GradAll = 0xF000,
};
MAKE_ENUM_FLAGS(TextPrintType);

class NOVTABLE GadgetClass : public LinkClass
{
public:

	//Destructor
	virtual ~GadgetClass() RX;

	//LinkClass
	virtual GadgetClass* GetNext() R0;
	virtual GadgetClass* GetPrev() R0;
	virtual void Zap() RX;
	virtual GadgetClass* Remove() R0;

	//GadgetClass
	virtual DWORD Input() R0;
	virtual void DrawAll(bool bForced) RX;
	virtual void DeleteList() RX;
	virtual GadgetClass* ExtractGadget(unsigned int nID) R0;
	virtual void MarkListToRedraw() RX;
	virtual void Disable() RX;
	virtual void Enable() RX;
	virtual unsigned int const GetID() R0;
	virtual void MarkRedraw() RX;
	virtual void PeerToPeer(unsigned int Flags, DWORD* pKey, GadgetClass* pSendTo) RX;
	virtual void SetFocus() RX;
	virtual void KillFocus() RX;
	virtual bool IsFocused() R0;
	virtual bool IsListToRedraw() R0;
	virtual bool IsToRedraw() R0;
	virtual void SetPosition(int X, int Y) RX;
	virtual void SetDimension(int Width, int Height) RX;
	virtual bool Draw(bool bForced) R0;
	virtual void OnMouseEnter() RX;
	virtual void OnMouseLeave() RX;
	virtual void StickyProcess(GadgetFlag Flags) RX;
	virtual bool Action(GadgetFlag Flags, DWORD* pKey, KeyModifier Modifier) R0;
	virtual bool Clicked(DWORD* pKey, GadgetFlag Flags, int X, int Y, KeyModifier Modifier) R0; // Clicked On

	//Non virtual
	GadgetClass& operator=(GadgetClass& another) { JMP_THIS(0x4B5780); }
	GadgetClass* ExtractGadgetAt(int X, int Y) { JMP_THIS(0x4E15A0); }

	//Statics
	static int __fastcall GetColorScheme() { JMP_STD(0x4E12D0); }

	//Constructors
	GadgetClass(int nX, int nY, int nWidth, int nHeight, GadgetFlag eFlag, bool bSticky) noexcept
		: GadgetClass(noinit_t()) {
		JMP_THIS(0x4E12F0);
	}

	GadgetClass(GadgetClass& another) noexcept
		: GadgetClass(noinit_t()) {
		JMP_THIS(0x4E1340);
	}

protected:
	explicit __forceinline GadgetClass(noinit_t)  noexcept
		: LinkClass(noinit_t())
	{
	}

	//Properties
public:

	int X;
	int Y;
	int Width;
	int Height;
	bool NeedsRedraw;
	bool IsSticky;
	bool Disabled;
	GadgetFlag Flags;
};

class NOVTABLE TextLabelClass : public GadgetClass
{
public:
	//Non virtual

	//Statics

	//Constructors
	TextLabelClass(wchar_t* pText, int X, int Y, int ColorSchemeIndex, TextPrintType style) noexcept
		: GadgetClass(noinit_t()) {
		JMP_THIS(0x72A440);
	}
protected:
	explicit __forceinline TextLabelClass(noinit_t)  noexcept
		: GadgetClass(noinit_t())
	{
	}

	//Properties
public:

	void* UserData1;
	void* UserData2;
	DWORD Style;
	wchar_t* Text;
	int ColorSchemeIndex;
	DWORD PixWidth;
	DWORD anim_dword3C;
	bool SkipDraw;
	bool Animate;
	DWORD AnimPos;
	DWORD AnimTiming;
};

// https://github.com/electronicarts/CnC_Remastered_Collection/blob/7d496e8a633a8bbf8a14b65f490b4d21fa32ca03/REDALERT/MSGLIST.H
class MessageListClass
{
public:
	static constexpr reference<MessageListClass, 0xA8BC60u> const Instance{};

	explicit MessageListClass() noexcept
	{
		JMP_THIS(0x5D39D0);
	}

	~MessageListClass() noexcept
	{
		JMP_THIS(0x5D3A40);
	}

	void Init(int X, int Y, int MaxMsg, int MaxChars, int Height, int EditX, int EditY, int EnableOverflow, int OverflowStart, int OverflowEnd, int Width = 640)
	{
		JMP_THIS(0x5D3A60);
	}

	TextLabelClass* AddMessage(const wchar_t* Name, int ID, const wchar_t* Message, int ColorSchemeIdx, TextPrintType Style, int Timeout, bool SinglePlayer)
	{
		JMP_THIS(0x5D3BA0);
	}

	wchar_t* GetMessage(int ID) const
	{
		JMP_THIS(0x5D3F60);
	}

	TextLabelClass* GetLabel(int ID) const
	{
		JMP_THIS(0x5D3F90);
	}

	bool ConcatMessage(const wchar_t* Name, int ID, const wchar_t* Message, int Timeout)
	{
		JMP_THIS(0x5D3FC0);
	}

	void SetEditFocus() const
	{
		JMP_THIS(0x5D41E0);
	}

	bool HasEditFocus() const
	{
		JMP_THIS(0x5D41F0);
	}

	TextLabelClass* AddEdit(int ColorSchemeIdx, TextPrintType Style, wchar_t* Message, char CursorCharacter = 0, int Width = 640)
	{
		JMP_THIS(0x5D4210);
	}

	void RemoveEdit()
	{
		JMP_THIS(0x5D4390);
	}

	wchar_t* GetEditBuffer() const
	{
		JMP_THIS(0x5D4400);
	}

	void SetEditColor(int ColorSchemeIdx)
	{
		JMP_THIS(0x5D4410);
	}

	int Manage()
	{
		JMP_THIS(0x5D4430);
	}

	int Input(int& Input, int DefInput = 0)
	{
		JMP_THIS(0x5D4510);
	}

	void Draw() const
	{
		JMP_THIS(0x5D49A0);
	}

	int NumMessages() const
	{
		JMP_THIS(0x5D4AA0);
	}

	void SetWidth(int width)
	{
		JMP_THIS(0x5D4AD0);
	}

	int TrimMessage(wchar_t* dest, wchar_t* src, int min_chars, int max_chars, int scandir)
	{
		JMP_THIS(0x5D4B20);
	}

	void ComputeY()
	{
		JMP_THIS(0x5D4BF0);
	}

	// if pLabel is given, the message will be {$pLabel}:{$pMessage}
	// else it will be just {$pMessage}
	void PrintMessage(const wchar_t* pMessage, int durationFrames = 0x96, int nColorSchemeIndex = ColorScheme::White, bool bSilent = false)
	{
		this->AddMessage(nullptr, 0, pMessage, nColorSchemeIndex, static_cast<TextPrintType>(0x4046), durationFrames, bSilent);
	}

	void PrintMessage(const wchar_t* pMessage, double durationMinutes, int nColorSchemeIndex = ColorScheme::White, bool bSilent = false)
	{
		this->AddMessage(nullptr, 0, pMessage, nColorSchemeIndex, static_cast<TextPrintType>(0x4046), static_cast<int>(durationMinutes * 900), bSilent);
	}


	TextLabelClass* MessageList;
	Point2D MessagePos;
	int MaxMessageCount;
	int MaxCharacters;
	int Height;
	bool EnableOverflow;
	bool IsEdit;
	bool AdjustEdit;
	Point2D EditPos;
	TextLabelClass* EditLabel;
	wchar_t EditBuffer[162];
	wchar_t OverflowBuffer[162];
	DWORD EditCurrentPos;
	DWORD EditInitialPos;
	wchar_t CursorCharacter;
	DWORD OverflowStart;
	DWORD OverflowEnd;
	int Width;
	wchar_t MessageBuffers[14][162];
	wchar_t BufferAvail[14];
};

static_assert(sizeof(MessageListClass) == 0x149C);