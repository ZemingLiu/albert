// Copyright (c) 2022 Manuel Schneider

#pragma once
#include "albert/util/extensionwatcher.h"
#include <QAbstractTableModel>
#include <QListWidget>
#include <QStackedWidget>
#include <set>
namespace albert {
class ExtensionRegistry;
class ConfigWidgetProvider;
}

class ConfigProviderWidget final:
        public QWidget,
        public albert::ExtensionWatcher<albert::ConfigWidgetProvider>
{
    Q_OBJECT

public:
    explicit ConfigProviderWidget(albert::ExtensionRegistry&registry);

private:
    void resetUI();

protected:
    void onAdd(albert::ConfigWidgetProvider *t) override;
    void onRem(albert::ConfigWidgetProvider *t) override;

private:

    std::vector<albert::ConfigWidgetProvider*> providers;
    QListWidget list_widget;
    QStackedWidget stacked_widget;

};

