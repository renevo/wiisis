////////////////////////////////////////////////////
// Wii Remote Game File
// Copyright (C), RenEvo Software & Designs, 2007
//
// IWiiRemoteManager.h
//
// Purpose: Interface object
//	Describes a manager to handle the Wii Remote
//
// History:
//	- 11/15/07 : File created - KAK
////////////////////////////////////////////////////

#ifndef _IWIIREMOTEMANAGER_H_
#define _IWIIREMOTEMANAGER_H_

struct IWiiRemoteManager
{
	////////////////////////////////////////////////////
	// Destructor
	////////////////////////////////////////////////////
	virtual ~IWiiRemoteManager(void) {}

	////////////////////////////////////////////////////
	// Initialize
	//
	// Purpose: Find and prepare the Wii Remote
	////////////////////////////////////////////////////
	virtual void Initialize(void) = 0;

	////////////////////////////////////////////////////
	// Shutdown
	//
	// Purpose: Clean up
	////////////////////////////////////////////////////
	virtual void Shutdown(void) = 0;

	////////////////////////////////////////////////////
	// Update
	//
	// Purpose: Update the Wii Remote
	//
	// In:	bHaveFocus - TRUE if window has focus
	//		nUpdateFlags - Update flags
	////////////////////////////////////////////////////
	virtual void Update(bool bHaveFocus, int nUpdateFlags) = 0;

	////////////////////////////////////////////////////
	// UpdateHUD
	//
	// Purpose: Update the HUD elements for the remote
	//
	// In:	pHUD - HUD object
	////////////////////////////////////////////////////
	virtual void UpdateHUD(class CHUD *pHUD) = 0;

	////////////////////////////////////////////////////
	// EditorResetGame
	//
	// Purpose: Call when Editor game resets
	//
	// In:	bStart - TRUE if Editor game has started
	////////////////////////////////////////////////////
	virtual void EditorResetGame(bool bStart) = 0;

	////////////////////////////////////////////////////
	// SetMasterEnabled
	//
	// Purpose: Set if Wii Remote is utilized
	//
	// In:	bOn - TRUE to use the remote, FALSE to turn
	//		it off
	////////////////////////////////////////////////////
	virtual void SetMasterEnabled(bool bOn) = 0;

	////////////////////////////////////////////////////
	// IsMasterEnabled
	//
	// Purpose: Returns TRUE if Remote is enabled
	////////////////////////////////////////////////////
	virtual bool IsMasterEnabled(void) const = 0;

	////////////////////////////////////////////////////
	// GetLockedEntity
	//
	// Purpose: Returns locked entity
	//
	// Out:	vOffset - Locked offset
	////////////////////////////////////////////////////
	virtual struct IRenderNode* GetLockedEntity(Vec3 &vOffset) const = 0;

	////////////////////////////////////////////////////
	// FreezeMovement
	//
	// Purpose: Call to freeze movement for a bit
	//
	// Note: Used by gestures like throw to help prevent
	//	dizzy spells
	////////////////////////////////////////////////////
	virtual void FreezeMovement(void) = 0;

	////////////////////////////////////////////////////
	// IsMovementFrozen
	//
	// Purpose: Returns TRUE if movement is frozen
	////////////////////////////////////////////////////
	virtual bool IsMovementFrozen(void) const = 0;

	////////////////////////////////////////////////////
	// SetErrorLevel
	//
	// Purpose: Set the error level to be displayed
	//
	// In:	nLevel - Error message level
	////////////////////////////////////////////////////
	virtual void SetErrorLevel(int nLevel) = 0;

	////////////////////////////////////////////////////
	// ClearErrorLevel
	//
	// Purpose: Clear error
	//
	// In:	nLevel - Level to clear or -1 for all levels
	////////////////////////////////////////////////////
	virtual void ClearErrorLevel(int nLevel = -1) = 0;

	////////////////////////////////////////////////////
	// SetRemote
	//
	// Purpose: Set the Wii Remote
	//
	// In:	pRemote - Wii Remote to use
	////////////////////////////////////////////////////
	virtual void SetRemote(struct IWR_WiiRemote *pRemote) = 0;

	////////////////////////////////////////////////////
	// GetRemote
	//
	// Purpose: Return the Wii Remote in use
	////////////////////////////////////////////////////
	virtual struct IWR_WiiRemote* GetRemote(void) const = 0;

	////////////////////////////////////////////////////
	// Rumble
	//
	// Purpose: Have the remote rumble for a set time
	//
	// In:	fDuration - How long to rumble
	////////////////////////////////////////////////////
	virtual void Rumble(float fDuration) = 0;

	////////////////////////////////////////////////////
	// OnWeaponShoot
	//
	// Purpose: Call when a weapon fires for rumble control
	//
	// In:	nShooterId - Id of shooter
	////////////////////////////////////////////////////
	virtual void OnWeaponShoot(unsigned int nShooterId) = 0;
};

#endif //_IWIIREMOTEMANAGER_H_