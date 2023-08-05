import os
import glob
import csv
import traceback
import xml.etree.ElementTree as ET

def parse_xml_to_csv(xml_file, csv_file):
    try:
        tree = ET.parse(xml_file+".xml")
        root = tree.getroot()
        # Prepare the CSV file and header
        with open(csv_file + ".csv", 'w', newline='') as csvfile:
            writer = csv.writer(csvfile)

            # Write header row
            header = ['name', 'nominal', 'lifetime', 'restock', 'min', 'quantmin', 'quantmax', 'cost',
                    'count_in_cargo', 'count_in_hoarder', 'count_in_map', 'count_in_player', 'crafted', 'deloot']
            
            # Update header to include category, tag, usage and value columns dynamically
            for i in range(1, 5):
                header.append(f'category_{i}')
            for i in range(1, 5):
                header.append(f'tag_{i}')
            for i in range(1, 5):
                header.append(f'usage_{i}')
            for i in range(1, 5):
                header.append(f'value_{i}')

            writer.writerow(header)

            for type_element in root.findall('type'):
                # Get the data for each element
                name = type_element.get('name')
                nominal = type_element.find('nominal').text if type_element is not None and type_element.find('nominal') is not None else None
                lifetime = type_element.find('lifetime').text if type_element is not None and type_element.find('lifetime') is not None else None
                restock = type_element.find('restock').text if type_element is not None and type_element.find('restock') is not None else None
                min_value = type_element.find('min').text if type_element is not None and type_element.find('min') is not None else None
                quantmin = type_element.find('quantmin').text if type_element is not None and type_element.find('quantmin') is not None else None
                quantmax = type_element.find('quantmax').text if type_element is not None and type_element.find('quantmax') is not None else None
                cost = type_element.find('cost').text if type_element is not None and type_element.find('cost') is not None else None

                # Extract data from flags
                flags_element = type_element.find('flags')
                count_in_cargo = flags_element.get('count_in_cargo', '0')
                count_in_hoarder = flags_element.get('count_in_hoarder', '0')
                count_in_map = flags_element.get('count_in_map', '0')
                count_in_player = flags_element.get('count_in_player', '0')
                crafted = flags_element.get('crafted', '0')
                deloot = flags_element.get('deloot', '0')
                
                # Extract data from categories
                category_users = [usage.get('name', '') for usage in type_element.findall('category')]
                categories = category_users[:4]  # Take up to 4 categories
                while len(categories) < 4:
                    categories.append('')  # Fill in empty values if there are less than 4 categories
                
                # Extract data from tags
                tag_users = [usage.get('name', '') for usage in type_element.findall('tag')]
                tags = tag_users[:4]  # Take up to 4 tags
                while len(tags) < 4:
                    tags.append('')  # Fill in empty values if there are less than 4 tags

                # Extract data from usage
                usage_users = [usage.get('user', '') for usage in type_element.findall('usage')]
                usages = usage_users[:4]  # Take up to 4 usages
                while len(usages) < 4:
                    usages.append('')  # Fill in empty values if there are less than 4 usages

                # Extract data from value
                value_users = [value.get('user', '') for value in type_element.findall('value')]
                values = value_users[:4]  # Take up to 4 values
                while len(values) < 4:
                    values.append('')  # Fill in empty values if there are less than 4 values

                # Write the row to CSV
                row_data = [name, nominal, lifetime, restock, min_value, quantmin, quantmax, cost,
                            count_in_cargo, count_in_hoarder, count_in_map, count_in_player, crafted, deloot,
                            *categories, *tags, *usages, *values]
                writer.writerow(row_data)
    except ET.ParseError as e:
        print(f"Error while parsing XML: {e}")
        return
    
def combine_xml_files(output_filename, directory="."):
    root = ET.Element("types")
    for filename in glob.iglob(os.path.join(directory, "**", "*_types.xml"), recursive=True):
        with open(filename, "r") as file:
            try:
                tree = ET.parse(file)
                root.append(tree.getroot())
            except Exception as e:
                print(f"Error parsing XML file: {filename}")
                print(traceback.format_exc())  # This will print the full error traceback for debugging
                continue

    # Parse the XML file
    combined_tree = ET.ElementTree(root)
    combined_tree.write(output_filename+".xml", encoding="utf-8", xml_declaration=True)

    # test remove after written
    content= []
    with open(output_filename+".xml",'r') as file:
        for line in file:
            if line.strip() == "<types><types>":
                content.append("<types>\n")
            elif line.strip() == "</types></types>":
                content.append("</types>\n")
            elif line.strip() != "</types><types>":
                content.append(line)
            
    with open(output_filename+".xml",'w') as file:
        for e in content:
            file.write(e)

if __name__ == "__main__":
    output_filename = "output"
    combine_xml_files(output_filename, "../../dayzOffline.chernarusplus/db_mods/")
    parse_xml_to_csv(output_filename, output_filename)
