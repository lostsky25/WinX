#pragma once
#include <map>
#include <queue>

//#include "XButton.h"
//#include "XComboBox.h"

//#include "XApplication.h"

#include "XApplet.h"
#include "XTypes.h"

class XButton;
class XComboBox;

enum LayoutDirection {
	Vertical = 0,
	Horizontal = 1,
	None = 2,
};

class XLayout
{
public:

	/*static XTypes::XMargins margins();
	static void setMargin(XTypes::XMargins);
	static void setMargin(int, int, int, int);*/
	static std::vector<std::pair<XTypes::XRect, XTypes::XMargins>> _properties;					//Window margins (left, top, right, bottom).	

protected:
	friend class XApplication;


	int _count = 0;
	static int _layoutId;

	LayoutDirection dir;										//Current direction.
	virtual void deleteApplet(int) = 0;							//Delete some applet by id.
	virtual void destroyedLayout() = 0;							//Clear layout and freeing up memory.
	virtual void activate() = 0;								//By default -> true;
	//virtual void addApplet(XApplet) = 0;
	//virtual void addChildLayout(XLayout) = 0;
	//virtual void addChildWidget(...) = 0;
	//virtual void addLayout(XLayout*, int) = 0;
	virtual void addSpacing(int) = 0;							//Set spacing between applets.
	//virtual void addStretch(int) = 0;
		//connect(const QObject*, const char*, const QObject*, const char*, Qt::ConnectionType) : QMetaObject::Connection
		//connect(const QObject*, const QMetaMethod&, const QObject*, const QMetaMethod&, Qt::ConnectionType) : QMetaObject::Connection
		//connect(const QObject*, const char*, const char*, Qt::ConnectionType) const : QMetaObject::Connection
		//connect(const QObject*, PointerToMemberFunction, const QObject*, PointerToMemberFunction, Qt::ConnectionType) : QMetaObject::Connection
		//connect(const QObject*, PointerToMemberFunction, Functor) : QMetaObject::Connection
		//connect(const QObject*, PointerToMemberFunction, const QObject*, Functor, Qt::ConnectionType) : QMetaObject::Connection
	virtual int count() = 0;									//Get count of applets in the layout.
		//disconnect(const QObject*, const char*, const QObject*, const char*) : bool
		//disconnect(const QObject*, const QMetaMethod&, const QObject*, const QMetaMethod&) : bool
		//disconnect(const char*, const QObject*, const char*) const : bool
		//disconnect(const QObject*, const char*) const : bool
		//disconnect(const QMetaObject::Connection&) : bool
		//disconnect(const QObject*, PointerToMemberFunction, const QObject*, PointerToMemberFunction) : bool
		
		/*eventFilter(QObject*, QEvent*) : bool
		expandingDirections() const : Qt::Orientations
		findChild(const QString&, Qt::FindChildOptions) const : T
		findChildren(const QString&, Qt::FindChildOptions) const : QList<T>
		findChildren(const QRegularExpression&, Qt::FindChildOptions) const : QList<T>
		geometry() const : QRect
		getContentsMargins(int*, int*, int*, int*) const
		hasHeightForWidth() const : bool
		heightForWidth(int) const : int
		indexOf(QWidget*) const : int
		indexOf(QLayoutItem*) const : int
		inherits(const char*) const : bool
		insertItem(int, QLayoutItem*)
		insertLayout(int, QLayout*, int)	insertSpacerItem(int, QSpacerItem*)
		insertSpacing(int, int)
		insertStretch(int, int)
		insertWidget(int, QWidget*, int, Qt::Alignment)
		installEventFilter(QObject*)
		invalidate()
		isEmpty() const : bool
		isEnabled() const : bool
		isSignalConnected(const QMetaMethod&) const : bool
		isWidgetType() const : bool
		isWindowType() const : bool
		itemAt(int) const : QLayoutItem *
		killTimer(int)
		layout() : QLayout *
		maximumSize() const : QSize
		menuBar() const : QWidget *
		metaObject() const : const QMetaObject*
		minimumHeightForWidth(int) const : int
		minimumSize() const : QSize
		moveToThread(QThread*)
		objectName() const : QString
		parent() const : QObject *
		parentWidget() const : QWidget *
		property(const char*) const : QVariant
		receivers(const char*) const : int
		removeEventFilter(QObject*)
		removeItem(QLayoutItem*)
		removeWidget(QWidget*)
		replaceWidget(QWidget*, QWidget*, Qt::FindChildOptions) : QLayoutItem *
		sender() const : QObject *
		senderSignalIndex() const : int
		setAlignment(QWidget*, Qt::Alignment) : bool
		setAlignment(QLayout*, Qt::Alignment) : bool
		setContentsMargins(int, int, int, int)
		setContentsMargins(const QMargins&)
		setDirection(QBoxLayout::Direction)
		setEnabled(bool)
		setGeometry(const QRect&)
		setMenuBar(QWidget*)
		setObjectName(const QString&)
		setParent(QObject*)
		setProperty(const char*, const QVariant&) : bool
		setSizeConstraint(QLayout::SizeConstraint)
		setSpacing(int)
		setStretch(int, int)
		setStretchFactor(QWidget*, int) : bool
		setStretchFactor(QLayout*, int) : bool
		signalsBlocked() const : bool
		sizeConstraint() const : QLayout::SizeConstraint
		sizeHint() const : QSize
		spacerItem() : QSpacerItem *
		spacing() const : int
		startTimer(int, Qt::TimerType) : int
		startTimer(std::chrono::milliseconds, Qt::TimerType) : int
		staticMetaObject :
	stretch(int) const : int
		takeAt(int) : QLayoutItem *
		thread() const : QThread *
		timerEvent(QTimerEvent*)
		tr(const char*, const char*, int) : QString
		update()
		widget() : QWidget**/
};
