import model_view_controller as mvc
from  basic_backend import *


def main():

    my_items = [
        {'name': 'bread', 'price': 0.5, 'quantity': 20},
        {'name': 'milk', 'price': 1.0, 'quantity': 10},
        {'name': 'wine', 'price': 10.0, 'quantity': 5},
    ]

    # CREATE
    model = mvc.ModelBasic(my_items)
    view = mvc.View()
    controller = mvc.Controller(model, view)
    model.create_items(my_items)
    controller.insert_item('beer', price=3.0, quantity=15)

    view.display_item_stored('beer', my_items)
    # if we try to re-create an object we get an ItemAlreadyStored exception
    controller.insert_item('beer', price=2.0, quantity=10)

    # READ
    print('READ items')
    controller.show_items(True)
    # if we try to read an object not stored we get an ItemNotStored exception
    print('READ chocolate')
    controller.show_item('chocolate')
    print('READ bread')
    controller.show_item('bread')
    
    # UPDATE
    print('UPDATE bread')
    controller.update_item('bread', price=2.0, quantity=30)
    # if we try to update an object not stored we get an ItemNotStored exception
    print('UPDATE chocolate')
    controller.update_item('chocolate', price=10.0, quantity=20)

    # DELETE
    print('DELETE beer')
    controller.delete_item('beer')
    # if we try to delete an object not stored we get an ItemNotStored exception
    print('DELETE chocolate')
    controller.delete_item('chocolate')

    print('READ items')
    controller.show_items()

if __name__ == '__main__':
    main()