========================================================================
    WIN32 APPLICATION : DreamCoastEngine Basic Project Overview
========================================================================

AppWizard has created this DreamCoastEngine Basic application for you.

This file contains a summary of what you will find in each of the files that
make up your DreamCoastEngine Basic application.


DreamCoastEngine Basic.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

DreamCoastEngine Basic.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

DreamCoastEngine Basic.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
AppWizard has created the following resources:

DreamCoastEngine Basic.rc
    This is a listing of all of the Microsoft Windows resources that the
    program uses.  It includes the icons, bitmaps, and cursors that are stored
    in the RES subdirectory.  This file can be directly edited in Microsoft
    Visual C++.

Resource.h
    This is the standard header file, which defines new resource IDs.
    Microsoft Visual C++ reads and updates this file.

DreamCoastEngine Basic.ico
    This is an icon file, which is used as the application's icon (32x32).
    This icon is included by the main resource file DreamCoastEngine Basic.rc.

small.ico
    This is an icon file, which contains a smaller version (16x16)
    of the application's icon. This icon is included by the main resource
    file DreamCoastEngine Basic.rc.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named DreamCoastEngine Basic.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////

DreamCoast Engine 0.01

���� Ŭ���� ������
World
World�� �����ϴ� Ŭ����  
(World�� ö���� ���� �÷��� ȭ�鸸�� �����Ѵ�)

World has below classes as variable

map -> ���� �����ϴ� Ŭ����
		- x*y�� isometric �������� 2���� �迭�� ������ �ְ�, �� ������ ���� ��ȣ�ۿ��� �ǽ��Ѵ�(���� �߰�)		
		
KeyControl -> 
������ Ű ��Ʈ�� ���� ������ �����ϴ� Ŭ����
���콺 ��ġ ����, Ű���� �Է� ������ �Է±��μ��� �Է��� �����Ѵ�.

UI -> ���� UI�� �����ϴ� Ŭ���� // �ڽ� Ŭ������ ����â, �κ�â��
		- �»��: ü��, ����â, �޴� Ŭ��â ���

Object -> ȭ����� Object���� �����ϴ� Ŭ����
		- �÷����� ��� ��ǥ�� ������ �־���ϸ�,
			���ڽ��� �̿��� Ÿ���� �ƴ�, isometric�����
			��ų ���, Ÿ���� ����Ѵ�. (���� �߰�)

		- �÷��̾� �� ���� ĳ���͸� �����ϴ� Ŭ����	 
		- ���� - AI FSM �߰�			

WorldRenderer-> WorldRenderer Refers World Class 
		- LineTo�� �̿�, IsoMetric���� Render�ϵ�, �� ������ �߾ӿ� ��ǥ�� Text�� �����Ѵ�.
		
�� ��

0. â ������, â�� ������¡ ���� �ʵ��� ������ �� �ǽ��Ѵ�. 

1. Map ������ ������� ���� Isometric���� �����Ѵ�. (WorldRenderer) - ī�޶� �並 �̿��� �̵������� ���� �ǽ�

1-1 ���������μ� �ش� �� ���κп� User Interface�� ���� �������Ѵ�. ���� Ŭ������ ����� �����Ҽ� �ֵ��� �Ѵ�.
���̾�� ���� �Ʒ����� ��, ������Ʈ, UI������ �����Ѵ�.

2. User�� �ش� ��ǥ�� ������ �ÿ�, �ش� ��ǥ���� Object�� �����Ѵ�. 
�׳� Render�� �ص� �ǰ����� ���� Object������ ���� Picker�μ��� ���(Ȯ�强)�� �����Ͽ� �ǽ��Ѵ�.
- Picker�� ��쿡 �� Ÿ���� ������ ��Ʈ�ڽ��� ������ �������ϳ�?

-�ϴ� �⺻���� ������,
* Click�� ��ǥ���� ������ �� ��ǥ�� ������ �ȿ� ���� ��쿡, �ش� Ÿ���� ��ǥ�� �� ������Ʈ�� �����ϰų�,
 ������ ���ش�. �ε�,
  ��ǥ�� ������ �ȿ� �ִ� ���� ��� 

3. Player Object�� ������ �߰��� ��, �̵��Ҽ� �ְ� �Ѵ�. (ȭ��ǥŰ)
 - �̵� �� ó���� ��� ���� ����غ���(���� �����̸� IsoMetric ������δ� ������ ���� �����̴� �ִϸ��̼��� �ȴ�.)
 - ���� ������� �ϴ� ������ Ű���� ����� �׼��� �����̹Ƿ� IsoMetric�� ���� �ô� ������� ����غ���.
 - IsoMetric���� ������ Top View�� �����Ҽ� �ִ� ����� ����غ���.
 - Ÿ�� ������ Hitbox�� �ƴ� Ÿ�� ������� Ÿ�� ������ ��ų ������ ���Ѵ�. (���� ��׳���ũ �¶����� �׷��� ��ó��)
 - �̵� �� ������ �÷��̾ ��ġ�� Ÿ�� ��ġ�� ȭ�鿡 ����Ѵ�.
 
 4. Monster Object�� ������ �߰��� �� ���� ���� (���� ���� ��)