/*******************************************************************************
 * This file is part of ROM Patcher.
 * 
 * Copyright (c) 2014 xperia64.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the GNU Public License v3.0
 * which accompanies this distribution, and is available at
 * http://www.gnu.org/licenses/gpl.html
 * 
 * Contributors:
 * 	Paul Kratt - main MultiPatch application for Mac OSX
 * 	byuu - UPS and BPS patchers
 * 	Neil Corlett - IPS patcher
 * 	Daniel Ekstr'm - PPF patcher
 * 	Josh MacDonald - XDelta
 * 	Colin Percival - BSDiff
 * 	xperia64 - port to Android and IPS32 support
 ******************************************************************************/
package com.xperia64.rompatcher;

public class Globals {

	public static String fileToPatch="";
	public static String patchToApply="";
	public static boolean mode=false;
	public static String msg="";
	// Patch types in no real order
	public static final int TYPE_UPS=0;
	public static final int TYPE_XDELTA=1;
	public static final int TYPE_BPS=2;
	public static final int TYPE_BSDIFF=3;
	public static final int TYPE_PPF=4;
	public static final int TYPE_IPS=5;
	public static final int TYPE_IPS32=6;
}