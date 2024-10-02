#pragma once
#include <qwidget.h>
#include "service.h"
#include <QTableView>
#include <QBrush>
#include <QHBoxLayout>
#include <QPushButton>

class MytableModel : public QAbstractTableModel {
private:
	vector<masina> masini;
public:
	MytableModel(vector<masina> ma) : masini{ ma } {}

	int rowCount(const QModelIndex& parent = QModelIndex()) const override {
		return masini.size();
	}

	int columnCount(const QModelIndex& parent = QModelIndex()) const override {
		return 4;
	}

	void setMasini(vector<masina> ma){
		masini = ma;
		auto topLeft = createIndex(0, 0);
		auto buttomRight = createIndex(rowCount(), columnCount());
		emit dataChanged(topLeft, buttomRight);
		emit layoutChanged();
	}


	QVariant data(const QModelIndex& index, int role) const override {
		if (role == Qt::DisplayRole) {
			masina m = masini[index.row()];
			if (index.column() == 0)
				return QString::fromStdString(m.get_nrin());
			if (index.column() == 1)
				return QString::fromStdString(m.get_denumire());
			if (index.column() == 2)
				return QString::number(m.get_an());
			if (index.column() == 3)
				return QString::fromStdString(m.get_tip());
		}
		if (role == Qt::BackgroundRole) {
			masina m = masini[index.row()];
			string tip = m.get_tip();

			if (tip == "sedan")
				return QBrush("red");
			else if (tip == "hatch")
				return QBrush("gray");
			else if (tip == "suv")
				return QBrush("green");
			else if (tip == "van")
				return QBrush("blue");

		}
		return QVariant();
	}
};



class gui: public QWidget
{
private:
	service& ser;
	QTableView* tabel;
	MytableModel* model;
	QHBoxLayout* mainl;
	QVBoxLayout* mainv;
	QPushButton* btnPlus;
	QPushButton* btnMinus;
	QPushButton* btnSterge;
	QPushButton* btnUndo;

	vector<int> stergere;

public:
	void init() {
		tabel = new QTableView;
		model = new MytableModel(ser.getAllService());

		tabel->setModel(model);

		mainl = new QHBoxLayout{};
		mainv = new QVBoxLayout{};
		mainl->addWidget(tabel);

		setLayout(mainl);

		btnPlus = new QPushButton("&+");
		btnMinus = new QPushButton("&-");
		btnSterge = new QPushButton("&Sterge");
		btnUndo = new QPushButton("&Undo");
		mainv->addWidget(btnPlus);
		mainv->addWidget(btnMinus);
		mainv->addWidget(btnSterge);
		mainv->addWidget(btnUndo);

		mainl->addLayout(mainv);
	}

	void reload() {
		model->setMasini(ser.getAllService());
		tabel->setModel(model);
	}

	void conexiuni() {
		QWidget::connect(btnPlus, &QPushButton::clicked, [&]() {
			ser.increment();
			reload();
			stergere.clear();
			//ser.addUndoInc(ser);
			});

		QWidget::connect(btnMinus, &QPushButton::clicked, [&]() {
			ser.decrement();
			reload();
			stergere.clear();
			//ser.addUndoDec(ser);
			});

		QWidget::connect(btnSterge, &QPushButton::clicked, [&]() {
			ser.sterge(stergere);
			stergere.clear();
			reload();
			});

		QWidget::connect(tabel, &QTableView::clicked, [&](const QModelIndex index) {
			stergere.push_back(index.row());
			});

		QWidget::connect(btnUndo, &QPushButton::clicked, [&]() {
			//ser.undo();
			stergere.clear();
			reload();
			});

	}


	gui(service& s) : ser{ s } {
		init();
		conexiuni();
		reload();
	}
};

